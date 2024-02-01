#include <stdio.h>


// build a parser "Adjective" to recognize descriptions
mpc_parser_t* Adjective = mpc_or(4,
	mpc_sym("wow"), mpc_sym("many"), mpc_sym("so"), mpc_sym("such")
);

// build a parser "Noun" to recognize things
mpc_parser_t* Noun = mpc_or(5,
	mpc_sym("lisp"), mpc_sym("language"), 
	mpc_sym("book"), mpc_sym("build"),
	mpc_sym("c")
)

mpc_parser_t* Phrase = mpc_and(2, mpcf_strfold,
	Adjective, Noun, free);
	
mpc_parser_t* Doge = mpc_many(mpcf_strfold, Phrase);

// have now taken a finite number of re-write rules to create an "infinite" language
// some possible string 'Doge' could accept:

// "wow book such language many lisp"
// "so c such build language"
// ""
// "wow lisp wow c many language"
// "so c"

//
//
// recreate previous examples using new method:

mpc_parser_t* Adjective = mpc_new("adjective");
mpc_parser_t* Noun = mpc_new("noun");
mpc_parser_t* Phrase = mpc_new("phrase");
mpc_parser_t* Doge = mpc_new("doge"):

mpca_lang(MPCA_LANG_DEFAULT,
	"																		\
		adjective : \"wow\" | \"many\" | \"so\" | \"such\";					\
		noun	  : \"lisp\" | \"language\" | \"book\" | \"build\" | \"c\";	\
		phrase	  : <adjective> <noun>;										\
		doge	  : <phrase>*;												\
	",
		Adjective, Noun, Phrase, Doge);
// do some parsing here...
mpc_cleanup(4, Adjective, Noun, Phrase, Doge);


// special symbol rules on right hand side work as follows:
// "ab"			The string ab is required
// 'a'			The character a is required
// 'a' 'b'		First 'a' is required, then 'b' is required
// 'a' | 'b'	Either 'a' is required, or 'b' is required
// 'a'*			Zero or more 'a' are required
// 'a'+			One or more 'a' are required
// <abba>		The rule called abba is required


// some things to think about:
// why are there back slashes <\> in front of the quote marks <"> in the grammar?
// why are there back slashes <\> at the end of the line in the grammer


// some things to do:
// write down some more examples of string the <Doge> language contains
// descrive textually a grammer for decimal numbers such as 0.01 or 52.221
// describe textually a grammer for web URLs such as <https://www.buildyourownlisp.com>
// describe textually a grammer for simple english sentences such as:
//					"the cat sat on the mat"
// describe more formally the above grammers. use <|>, <*>, or any symbols of own invention
// textually describe a grammer for JSON