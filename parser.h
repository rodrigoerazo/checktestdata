// Generated by Bisonc++ V6.02.04 on Sun, 20 Oct 2019 22:27:51 +0200

#ifndef Parser_h_included
#define Parser_h_included

// $insert baseclass
#include "parserbase.h"
// $insert scanner.h
#include "scanner.h"


#undef Parser
    // CAVEAT: between the baseclass-include directive and the
    // #undef directive in the previous line references to Parser
    // are read as ParserBase.
    // If you need to include additional headers in this file
    // you should do so after these comment-lines.


class Parser: public ParserBase
{
    // $insert scannerobject
    Scanner d_scanner;

    public:
        Parser(): d_scanner() {}
        Parser(std::istream& in, int startState = 0): d_scanner(in)
	        { d_scanner.parserStart = startState; }
        int parse();

        // The final result of parsing:
        parse_t parseResult;

    private:
#if ( BISONCPP_VERSION >= 60000LL )
        void error();                   // called on (syntax) errors
#else
        void error(char const *msg);
#endif
        int lex();                      // returns the next token from the
                                        // lexical scanner.
        void print();                   // use, e.g., d_token, d_loc
#if ( BISONCPP_VERSION >= 60000LL )
        void exceptionHandler(std::exception const &exc);
#else
        void exceptionHandler__(std::exception const &exc);
#endif

    // support functions for parse():
#if ( BISONCPP_VERSION >= 60000LL )
        void executeAction_(int ruleNr);
        void errorRecovery_();
        void nextCycle_();
        void nextToken_();
        void print_();
#else
        void executeAction(int ruleNr);
        void errorRecovery();
        int lookup(bool recovery);
        void nextToken();
        void print__();
#endif
};


#endif