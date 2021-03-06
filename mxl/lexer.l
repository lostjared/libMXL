
%option noyywrap yylineno nodefault
%option prefix="mxl"

%{
    #include "symbol.hpp"
    #include "parser.tab.hh"
%}



%%

"=>" { return ARROW; }
"=" { return yytext[0]; }
[a-zA-Z_][a-zA-Z0-9_]* { mxllval.s = new Symbol(yytext); return ID; }
\"(([^\"]|\\\")*[^\\])?\" { mxllval.s = new Symbol(yytext); return STR; }
[ \t] { }
"\n" { return EOL; }
"\\\n" { }
. {  }
%%


