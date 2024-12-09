# Digital Design Flow with Design Compiler, TetraMax, and Tessent

This README outlines the synthesis and testing process for a circuit using **Synopsys Design Compiler (DC)**, **TetraMax**, and **Tessent**. The flow covers synthesis (with and without scan chain insertion), ATPG generation, and fault simulation.

**Note:** Replace `<circuit>` with your actual Verilog file name (e.g., `pre_norm` or `s38584_seq`) and `<clk>` with the actual clock signal name (e.g., `clk` or `CK`) before executing the commands.

---

## 1. Synopsys Design Compiler (DC) Flow

### Synthesis Without Scan Chain

#### Steps:

```bash
# 1. Invoke the Design Compiler shell
dc_shell-t

# 2. Read in the Verilog file of the circuit
read_file -format verilog <circuit>.v

# 3. Set the current design to the circuit name
current_design <circuit>

# 4. Link the design (resolve references)
link

# 5. Uniquify the design (ensures unique names for elements)
uniquify

# 6. Set the wire load model (for timing analysis)
set_wire_load_model -name wl10 -library l90sprvt_typ

# 7. Create the clock with a specified period (adjust for your circuit's clock)
create_clock <clk> -period 10

# 8. Run the synthesis with medium effort on mapping
compile -map_effort medium

# 9. Generate various reports (timing, area, power, resources)
report_timing > <circuit>_DC_woscan.timing
report_area > <circuit>_DC_woscan.area
report_power > <circuit>_DC_woscan.power
report_resource > <circuit>_DC_woscan.resource

# 10. Output the synthesized netlist and constraints
write -hierarchy -format verilog -output <circuit>_DC_woscan.v
write_sdc <circuit>_DC_woscan.sdc

# 11. Exit the DC session
exit
```

### Synthesis With Scan Chain

#### Steps:

```bash
# 1. Invoke the Design Compiler shell
dc_shell-t

# 2. Read in the Verilog file of the circuit
read_file -format verilog <circuit>.v

# 3. Set the current design to the circuit name
current_design <circuit>

# 4. Link the design (resolve references)
link

# 5. Uniquify the design (ensures unique names for elements)
uniquify

# 6. Set the wire load model (for timing analysis)
set_wire_load_model -name wl10 -library l90sprvt_typ

# 7. Set the scan configuration style to multiplexed flip-flops
set_scan_configuration -style multiplexed_flip_flop

# 8. Create the clock with a specified period
create_clock <clk> -period 10

# 9. Compile the design with scan chain insertion
compile -scan -map_effort medium

# 10. Configure the scan chain (define the number of chains)
set_scan_configuration -chain_count 10

# 11. Create a test protocol (infer clock and asynchronous modes)
create_test_protocol -infer_clock -infer_asynch

# 12. Preview the DFT (Design for Test) setup
preview_dft > <circuit>_DC_scan_pre.dft
dft_drc > <circuit>_DC_scan_pre.drc

# 13. Insert the DFT structures into the design
insert_dft

# 14. Run post-scan checks and generate reports
dft_drc > <circuit>_DC_scan_post.drc
report_scan_path > <circuit>_DC_scan_post.path

# 15. Generate various reports (timing, area, power, resources)
report_timing > <circuit>_DC_scan.timing
report_area > <circuit>_DC_scan.area
report_power > <circuit>_DC_scan.power
report_resource > <circuit>_DC_scan.resource

# 16. Output the synthesized netlist, test protocol, and constraints
write -hierarchy -format verilog -output <circuit>_DC_scan.v
write_test_protocol -output <circuit>_DC_scan.stil
write_sdc <circuit>_DC_scan.sdc

# 17. Exit the DC session
exit
```

---

## 2. TetraMax ATPG and Fault Simulation Flow

### ATPG Without Scan Chain

#### Steps:

```bash
# 1. Invoke TetraMax ATPG tool
tmax64 -s

# 2. Read in the synthesized Verilog netlist from DC
read_netlist <circuit>_DC_woscan.v

# 3. Load the library for fault simulation
read_netlist l90sprvt.v -library

# 4. Build the ATPG model for the circuit
run_build_model <circuit>

# 5. Run DRC (Design Rule Checks) for the netlist
run_drc

# 6. Set fault model to "stuck" (used for stuck-at fault simulation)
set_faults -model stuck

# 7. Add all possible faults to the design
add_faults -all

# 8. Set ATPG parameters (e.g., high merge, verbose output, full sequence ATPG)
set_atpg -merge high -verbose -full_seq_time {3600 86400} -full_seq_atpg

# 9. Run the ATPG to generate test patterns
run_atpg > <circuit>_DC_woscan_TMAX_atpg.log

# 10. Report fault coverage summary
set_faults -summary verbose
set_faults -report collapsed
report_summaries > <circuit>_DC_woscan_TMAX.sum

# 11. Write the faults and patterns to files
write_faults <circuit>_DC_woscan_TMAX_faults.rpt -all -replace
write_patterns <circuit>_DC_woscan_TMAX_test_patterns.stil -format stil -replace

# 12. Exit the TetraMax session
exit
```

### ATPG With Scan Chain

#### Steps:

```bash
# 1. Invoke TetraMax ATPG tool
tmax64 -s

# 2. Read in the synthesized Verilog netlist with scan chain from DC
read_netlist <circuit>_DC_scan.v

# 3. Load the library for fault simulation
read_netlist l90sprvt.v -library

# 4. Build the ATPG model for the circuit
run_build_model <circuit>

# 5. Run DRC with the scan chain netlist
run_drc <circuit>_DC_scan.stil

# 6. Set fault model to "stuck" (used for stuck-at fault simulation)
set_faults -model stuck

# 7. Add all possible faults to the design
add_faults -all

# 8. Set ATPG parameters (e.g., high merge, verbose output, and coverage)
set_atpg -merge high -verbose -abort_limit 250 -coverage 100 -decision random

# 9. Run the ATPG to generate test patterns
run_atpg > <circuit>_DC_scan_TMAX_atpg.log

# 10. Report fault coverage summary
set_faults -summary verbose
set_faults -report collapsed
report_summaries > <circuit>_DC_scan_TMAX.sum

# 11. Write the faults and patterns to files
write_faults <circuit>_DC_scan_TMAX_faults.rpt -all -replace
write_patterns <circuit>_DC_scan_TMAX_test_patterns.stil -format stil -replace

# 12. Exit the TetraMax session
exit
```

---

## 3. Tessent DFT Flow

### Scan Chain Insertion and Fastscan

#### Steps:

```bash
# 1. Invoke the Tessent shell
tessent -shell

# 2. Set the context for DFT (Design for Test) with scan chain insertion
set_context dft -scan

# 3. Load the ATPG cell library for the scan insertion
read_cell_library l90sprvt.atpg

# 4. Read the Verilog file of the circuit (no scan chain yet)
read_verilog <circuit>_noscan.v

# 5. Set the current design to the circuit name
set_current_design <circuit>

# 6. Add the clock to the design
add_clocks 0 <clk>

# 7. Configure test logic settings (clock and reset)
set_test_logic -clock on -reset on

# 8. Set the system mode to analysis for scan insertion
set_system_mode analysis

# 9. Set scan insertion options (number of scan chains)
set_scan_insertion_options -chain_count 10

# 10. Analyze the scan chains in the design
analyze_scan_chains

# 11. Insert the test logic (scan chain)
insert_test_logic

# 12. Write the updated design to a new file
write_design -output <circuit>_scan.v -replace

# 13. Write ATPG setup for the scan chain
write_atpg_setup <circuit>_scan -replace

# 14. Set the system mode to setup for fault simulation
set_system_mode setup

# 15. Run the Dofile for scan verification (ensure correct scan modes)
dofile <circuit>_scan_verify_scan_modes.dofile

# 16. Set the fault type to "stuck" for fault simulation
set_fault_type stuck

# 17. Create ATPG patterns automatically
create_patterns -auto

# 18. Report scan statistics
report_statistics

# 19. Exit the Tessent session
exit
```

### Mixed Flow: Design Compiler to Tessent Fastscan

#### Steps:

```bash
# 1. Convert the STIL file from Design Compiler to Tessent format
stil2mgc <circuit>_DC_scan.stil

# 2. Invoke the Tessent shell
tessent -shell

# 3. Set the context for ATPG pattern generation with scan
set_context patterns -scan

# 4. Load the ATPG cell library
read_cell_library l90sprvt.atpg

# 5. Read the synthesized Verilog netlist with scan chain
read_verilog <circuit>_DC_scan.v

# 6. Run the STIL do-file for the ATPG patterns
dofile <circuit>_DC_scan.stil.do

# 7. Set the system mode to analysis
set_system_mode analysis

# 8. Set the fault type to "stuck" for fault simulation
set_fault_type stuck

# 9. Create ATPG patterns automatically
create_patterns -auto

# 10. Report scan statistics
report_statistics

# 11. Exit the Tessent session
exit
```

---

## References

1. Synopsys Inc., "Design Compiler User Guide," Dec. 2004.
2. Synopsys Inc., "Design Compiler Command-Line Interface Guide."
3. Synopsys Inc., "Design Compiler Reference Manual."
4. IPCORE Lab Slide 2006, Tian-Sheuan Chang.
5. VLSI Testing Course Slide, Jing-Jia Liou.
6. CIC Training Center Slide, Hsin-Jung Huang.
7. Mentor Graphics (Siemens), "Tessent Scan and ATPG User's Manual," v2019.3.
8. Synopsys, "TetraMAX ATPG User Guide," J-2014.09-SP1.
9. Synopsys, "TestMAX ATPG User Guide," P-2019.03.
