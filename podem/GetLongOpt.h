/* $Id: GetLongOpt.h,v 1.1.1.1 2001/10/02 22:17:28 jjliou Exp $ */
/* S Manoharan. Advanced Computer Research Institute. Lyon. France */

#ifndef _GetLongOpt_h_
#define _GetLongOpt_h_

#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class GetLongOpt {
    public:
        enum OptType {NoValue, OptionalValue, MandatoryValue};
    private:
        struct Cell {
            const char *option;  // option name
            OptType type;     // option type
            const char *description;   // a description of option
            const char *value;   // value of option (string)
            Cell *next;    // pointer to the next cell

            Cell() { option = description = value = 0; type = NoValue; next = 0; }
        };
    private:
        Cell *table;          // option table
        const char *ustring;        // usage message
        char *pname;          // program basename
        char optmarker;       // option marker

        int enroll_done;         // finished enrolling
        Cell *last;           // last entry in option table

    private:
        char *basename(char * const pname) const;
        int setcell(Cell *c, char *valtoken, char *nexttoken, const char *name) const;
    public:
        explicit GetLongOpt(const char optmark = '-');
        ~GetLongOpt();

        int parse(int argc, char * const *argv);
        int parse(char * const str, char * const p);

        int enroll(const char * const opt, const OptType t,
                   const char * const desc, const char * const val);
        const char *retrieve(const char * const opt) const;

        void usage(ostream &outfile = cout) const;
        void usage(const char *str) { ustring = str; }
};

#endif /* _GetLongOpt_h_ */
