#############################################################################
#                         A C A D E M I C   C O P Y
# 
# This file was produced by an ACADEMIC COPY of Parser Generator. It is for
# use in non-commercial software only. An ACADEMIC COPY of Parser Generator
# can only be used by a student, or a member of an academic community. If
# however you want to use Parser Generator for commercial purposes then you
# will need to purchase a license. For more information see the online help or
# go to the Bumble-Bee Software homepage at:
# 
# http://www.bumblebeesoftware.com
# 
# This notice must remain present in the file. It cannot be removed.
#############################################################################

#############################################################################
# parser.v
# YACC verbose file generated from parser.y.
# 
# Date: 05/11/11
# Time: 02:41:24
# 
# AYACC Version: 2.07
#############################################################################


##############################################################################
# Rules
##############################################################################

    0  $accept : whole_program $end

    1  whole_program : sentence_list

    2  sentence_list : not_empty_sentence_list
    3                |

    4  not_empty_sentence_list : sentence
    5                          | not_empty_sentence_list sentence

    6  sentence : identification TOKEN_EQUAL arith_expr
    7           | identification TOKEN_COLON
    8           | identification error
    9           | input_keyword input_list
   10           | function parenthese_expr
   11           | function parenthese_expr modifier_list
   12           | function parenthese_expr TOKEN_EQUAL arith_expr
   13           | function parenthese_expr modifier_list TOKEN_EQUAL arith_expr
   14           | output_keyword output_list
   15           | if_sentence sentence_list TOKEN_ENDIF
   16           | if_sentence sentence_list else_sentence TOKEN_ENDIF
   17           | for_head for_1 for_2 for_3 sentence_list for_tail
   18           | repeat_keyword sentence_list TOKEN_UNTIL logic_expr
   19           | while_begin_keyword logic_expr sentence_list TOKEN_WHILE_END
   20           | wait_until_keyword logic_expr
   21           | goto_keyword identification
   22           | goto_keyword error
   23           | gosub_keyword identification
   24           | gosub_keyword error
   25           | on_keyword arith_expr TOKEN_GOTO identification_list
   26           | on_keyword arith_expr TOKEN_GOTO error
   27           | on_keyword arith_expr TOKEN_GOSUB identification_list
   28           | on_keyword arith_expr TOKEN_GOSUB error
   29           | on_keyword arith_expr error
   30           | on_keyword TOKEN_BASIC_ERROR TOKEN_GOTO identification
   31           | on_keyword TOKEN_BASIC_ERROR TOKEN_GOTO error
   32           | on_keyword TOKEN_BASIC_ERROR TOKEN_GOSUB identification
   33           | on_keyword TOKEN_BASIC_ERROR TOKEN_GOSUB error
   34           | on_keyword TOKEN_BASIC_ERROR error
   35           | TOKEN_RETURN
   36           | error

   37  output_keyword : TOKEN_OUTPUT_NAME
   38                 | output_keyword channel_number_keyword
   39                 | output_keyword channel_number_keyword TOKEN_COMMA

   40  input_keyword : TOKEN_INPUT_NAME
   41                | input_keyword channel_number_keyword
   42                | input_keyword channel_number_keyword TOKEN_COMMA

   43  input_list : input_item
   44             | input_list TOKEN_COMMA input_item

   45  input_item : identification
   46             | function parenthese_expr
   47             | function parenthese_expr modifier_list

   48  output_list : output_format
   49              | output_list TOKEN_COMMA output_format
   50              | output_list TOKEN_SEMICOLON output_format

   51  output_format : output_item
   52                | output_item TOKEN_LEFT_SQUARE_BRACKET arith_expr TOKEN_RIGHT_SQUARE_BRACKET
   53                | output_item TOKEN_LEFT_SQUARE_BRACKET arith_expr TOKEN_COMMA arith_expr TOKEN_RIGHT_SQUARE_BRACKET
   54                | output_item TOKEN_LEFT_SQUARE_BRACKET arith_expr error
   55                | output_item TOKEN_LEFT_SQUARE_BRACKET arith_expr TOKEN_COMMA arith_expr error

   56  output_item : TOKEN_STRING
   57              | arith_expr
   58              | number_string TOKEN_LEFT_PARENTHESIS arith_expr TOKEN_RIGHT_PARENTHESIS
   59              | number_string error
   60              | number_string TOKEN_LEFT_PARENTHESIS arith_expr error

   61  modifier_list : modifier parenthese_expr
   62                | modifier_list modifier parenthese_expr

   63  for_head : for_keyword identification
   64           | for_keyword error

   65  for_1 : TOKEN_EQUAL arith_expr
   66        | error

   67  for_2 : TOKEN_TO arith_expr
   68        | error

   69  for_3 : TOKEN_STEP arith_expr
   70        |

   71  for_tail : TOKEN_NEXT identification
   72           | TOKEN_NEXT error

   73  if_sentence : if_keyword logic_expr TOKEN_THEN
   74              | if_keyword logic_expr error

   75  else_sentence : TOKEN_ELSE sentence_list
   76                | else_sub_sentence sentence_list
   77                | else_sub_sentence sentence_list else_sentence

   78  else_sub_sentence : TOKEN_ELSEIF logic_expr TOKEN_THEN
   79                    | TOKEN_ELSEIF logic_expr error

   80  arith_expr : TOKEN_CONST_INT
   81             | TOKEN_CONST_DOUBLE
   82             | TOKEN_ON
   83             | identification
   84             | function parenthese_expr
   85             | function parenthese_expr modifier_list
   86             | arith_expr TOKEN_ADD arith_expr
   87             | arith_expr TOKEN_SUB arith_expr
   88             | arith_expr TOKEN_MUL arith_expr
   89             | arith_expr TOKEN_DIV arith_expr
   90             | TOKEN_LEFT_PARENTHESIS arith_expr TOKEN_RIGHT_PARENTHESIS
   91             | TOKEN_SUB arith_expr
   92             | error

   93  relative_expr : arith_expr TOKEN_EQUAL arith_expr
   94                | arith_expr TOKEN_NOT_EQUAL arith_expr
   95                | arith_expr TOKEN_GREAT arith_expr
   96                | arith_expr TOKEN_GREAT_EQUAL arith_expr
   97                | arith_expr TOKEN_LESS arith_expr
   98                | arith_expr TOKEN_LESS_EQUAL arith_expr
   99                | arith_expr error

  100  logic_expr : relative_expr
  101             | logic_expr TOKEN_AND logic_expr
  102             | logic_expr TOKEN_OR logic_expr
  103             | logic_expr TOKEN_XOR logic_expr
  104             | TOKEN_NOT logic_expr
  105             | TOKEN_LEFT_PARENTHESIS logic_expr TOKEN_RIGHT_PARENTHESIS
  106             | TOKEN_LEFT_PARENTHESIS logic_expr error

  107  parenthese_expr :
  108                  | TOKEN_LEFT_PARENTHESIS TOKEN_RIGHT_PARENTHESIS
  109                  | TOKEN_LEFT_PARENTHESIS arith_expr_list TOKEN_RIGHT_PARENTHESIS
  110                  | TOKEN_LEFT_PARENTHESIS arith_expr_list error

  111  arith_expr_list : arith_expr
  112                  | arith_expr_list TOKEN_COMMA arith_expr

  113  identification_list : identification
  114                      | identification_list TOKEN_COMMA identification

  115  identification : TOKEN_IDENTIFICATION

  116  function : TOKEN_INTEGER_FUNCTION_NAME
  117           | TOKEN_DOUBLE_FUNCTION_NAME

  118  modifier : TOKEN_MODIFY_NAME

  119  repeat_keyword : TOKEN_REPEAT

  120  while_begin_keyword : TOKEN_WHILE_BEGIN

  121  wait_until_keyword : TOKEN_WAIT_UNTIL

  122  gosub_keyword : TOKEN_GOSUB

  123  goto_keyword : TOKEN_GOTO

  124  on_keyword : TOKEN_ON

  125  for_keyword : TOKEN_FOR

  126  if_keyword : TOKEN_IF

  127  number_string : TOKEN_NUMBER_CHARACTER

  128  channel_number_keyword : TOKEN_CHANNEL_NUMBER


##############################################################################
# States
##############################################################################

state 0
	$accept : . whole_program $end
	sentence_list : .  (3)

	error  shift 1
	TOKEN_IF  shift 2
	TOKEN_FOR  shift 3
	TOKEN_REPEAT  shift 4
	TOKEN_WHILE_BEGIN  shift 5
	TOKEN_WAIT_UNTIL  shift 6
	TOKEN_ON  shift 7
	TOKEN_GOTO  shift 8
	TOKEN_GOSUB  shift 9
	TOKEN_RETURN  shift 10
	TOKEN_IDENTIFICATION  shift 11
	TOKEN_INTEGER_FUNCTION_NAME  shift 12
	TOKEN_DOUBLE_FUNCTION_NAME  shift 13
	TOKEN_OUTPUT_NAME  shift 14
	TOKEN_INPUT_NAME  shift 15
	.  reduce 3

	whole_program  goto 16
	sentence_list  goto 17
	not_empty_sentence_list  goto 18
	sentence  goto 19
	identification  goto 20
	input_keyword  goto 21
	function  goto 22
	output_keyword  goto 23
	if_sentence  goto 24
	for_head  goto 25
	repeat_keyword  goto 26
	while_begin_keyword  goto 27
	wait_until_keyword  goto 28
	goto_keyword  goto 29
	gosub_keyword  goto 30
	on_keyword  goto 31
	for_keyword  goto 32
	if_keyword  goto 33


state 1
	sentence : error .  (36)

	.  reduce 36


state 2
	if_keyword : TOKEN_IF .  (126)

	.  reduce 126


state 3
	for_keyword : TOKEN_FOR .  (125)

	.  reduce 125


state 4
	repeat_keyword : TOKEN_REPEAT .  (119)

	.  reduce 119


state 5
	while_begin_keyword : TOKEN_WHILE_BEGIN .  (120)

	.  reduce 120


state 6
	wait_until_keyword : TOKEN_WAIT_UNTIL .  (121)

	.  reduce 121


state 7
	on_keyword : TOKEN_ON .  (124)

	.  reduce 124


state 8
	goto_keyword : TOKEN_GOTO .  (123)

	.  reduce 123


state 9
	gosub_keyword : TOKEN_GOSUB .  (122)

	.  reduce 122


state 10
	sentence : TOKEN_RETURN .  (35)

	.  reduce 35


state 11
	identification : TOKEN_IDENTIFICATION .  (115)

	.  reduce 115


state 12
	function : TOKEN_INTEGER_FUNCTION_NAME .  (116)

	.  reduce 116


state 13
	function : TOKEN_DOUBLE_FUNCTION_NAME .  (117)

	.  reduce 117


state 14
	output_keyword : TOKEN_OUTPUT_NAME .  (37)

	.  reduce 37


state 15
	input_keyword : TOKEN_INPUT_NAME .  (40)

	.  reduce 40


state 16
	$accept : whole_program . $end  (0)

	$end  accept


state 17
	whole_program : sentence_list .  (1)

	.  reduce 1


state 18
	sentence_list : not_empty_sentence_list .  (2)
	not_empty_sentence_list : not_empty_sentence_list . sentence

	error  shift 1
	TOKEN_IF  shift 2
	TOKEN_FOR  shift 3
	TOKEN_REPEAT  shift 4
	TOKEN_WHILE_BEGIN  shift 5
	TOKEN_WAIT_UNTIL  shift 6
	TOKEN_ON  shift 7
	TOKEN_GOTO  shift 8
	TOKEN_GOSUB  shift 9
	TOKEN_RETURN  shift 10
	TOKEN_IDENTIFICATION  shift 11
	TOKEN_INTEGER_FUNCTION_NAME  shift 12
	TOKEN_DOUBLE_FUNCTION_NAME  shift 13
	TOKEN_OUTPUT_NAME  shift 14
	TOKEN_INPUT_NAME  shift 15
	.  reduce 2

	sentence  goto 34
	identification  goto 20
	input_keyword  goto 21
	function  goto 22
	output_keyword  goto 23
	if_sentence  goto 24
	for_head  goto 25
	repeat_keyword  goto 26
	while_begin_keyword  goto 27
	wait_until_keyword  goto 28
	goto_keyword  goto 29
	gosub_keyword  goto 30
	on_keyword  goto 31
	for_keyword  goto 32
	if_keyword  goto 33


state 19
	not_empty_sentence_list : sentence .  (4)

	.  reduce 4


state 20
	sentence : identification . TOKEN_EQUAL arith_expr
	sentence : identification . TOKEN_COLON
	sentence : identification . error

	error  shift 35
	TOKEN_COLON  shift 36
	TOKEN_EQUAL  shift 37


state 21
	sentence : input_keyword . input_list
	input_keyword : input_keyword . channel_number_keyword
	input_keyword : input_keyword . channel_number_keyword TOKEN_COMMA

	TOKEN_CHANNEL_NUMBER  shift 38
	TOKEN_IDENTIFICATION  shift 11
	TOKEN_INTEGER_FUNCTION_NAME  shift 12
	TOKEN_DOUBLE_FUNCTION_NAME  shift 13

	identification  goto 39
	input_list  goto 40
	function  goto 41
	channel_number_keyword  goto 42
	input_item  goto 43


state 22
	sentence : function . parenthese_expr
	sentence : function . parenthese_expr modifier_list
	sentence : function . parenthese_expr TOKEN_EQUAL arith_expr
	sentence : function . parenthese_expr modifier_list TOKEN_EQUAL arith_expr
	parenthese_expr : .  (107)

	TOKEN_LEFT_PARENTHESIS  shift 44
	.  reduce 107

	parenthese_expr  goto 45


state 23
	sentence : output_keyword . output_list
	output_keyword : output_keyword . channel_number_keyword
	output_keyword : output_keyword . channel_number_keyword TOKEN_COMMA

	error  shift 46
	TOKEN_ON  shift 47
	TOKEN_SUB  shift 48
	TOKEN_LEFT_PARENTHESIS  shift 49
	TOKEN_NUMBER_CHARACTER  shift 50
	TOKEN_CHANNEL_NUMBER  shift 38
	TOKEN_IDENTIFICATION  shift 11
	TOKEN_INTEGER_FUNCTION_NAME  shift 12
	TOKEN_DOUBLE_FUNCTION_NAME  shift 13
	TOKEN_CONST_INT  shift 51
	TOKEN_CONST_DOUBLE  shift 52
	TOKEN_STRING  shift 53

	identification  goto 54
	arith_expr  goto 55
	function  goto 56
	output_list  goto 57
	channel_number_keyword  goto 58
	output_format  goto 59
	output_item  goto 60
	number_string  goto 61


state 24
	sentence : if_sentence . sentence_list TOKEN_ENDIF
	sentence : if_sentence . sentence_list else_sentence TOKEN_ENDIF
	sentence_list : .  (3)

	error  shift 1
	TOKEN_IF  shift 2
	TOKEN_FOR  shift 3
	TOKEN_REPEAT  shift 4
	TOKEN_WHILE_BEGIN  shift 5
	TOKEN_WAIT_UNTIL  shift 6
	TOKEN_ON  shift 7
	TOKEN_GOTO  shift 8
	TOKEN_GOSUB  shift 9
	TOKEN_RETURN  shift 10
	TOKEN_IDENTIFICATION  shift 11
	TOKEN_INTEGER_FUNCTION_NAME  shift 12
	TOKEN_DOUBLE_FUNCTION_NAME  shift 13
	TOKEN_OUTPUT_NAME  shift 14
	TOKEN_INPUT_NAME  shift 15
	.  reduce 3

	sentence_list  goto 62
	not_empty_sentence_list  goto 18
	sentence  goto 19
	identification  goto 20
	input_keyword  goto 21
	function  goto 22
	output_keyword  goto 23
	if_sentence  goto 24
	for_head  goto 25
	repeat_keyword  goto 26
	while_begin_keyword  goto 27
	wait_until_keyword  goto 28
	goto_keyword  goto 29
	gosub_keyword  goto 30
	on_keyword  goto 31
	for_keyword  goto 32
	if_keyword  goto 33


state 25
	sentence : for_head . for_1 for_2 for_3 sentence_list for_tail

	error  shift 63
	TOKEN_EQUAL  shift 64

	for_1  goto 65


state 26
	sentence : repeat_keyword . sentence_list TOKEN_UNTIL logic_expr
	sentence_list : .  (3)

	error  shift 1
	TOKEN_IF  shift 2
	TOKEN_FOR  shift 3
	TOKEN_REPEAT  shift 4
	TOKEN_WHILE_BEGIN  shift 5
	TOKEN_WAIT_UNTIL  shift 6
	TOKEN_ON  shift 7
	TOKEN_GOTO  shift 8
	TOKEN_GOSUB  shift 9
	TOKEN_RETURN  shift 10
	TOKEN_IDENTIFICATION  shift 11
	TOKEN_INTEGER_FUNCTION_NAME  shift 12
	TOKEN_DOUBLE_FUNCTION_NAME  shift 13
	TOKEN_OUTPUT_NAME  shift 14
	TOKEN_INPUT_NAME  shift 15
	.  reduce 3

	sentence_list  goto 66
	not_empty_sentence_list  goto 18
	sentence  goto 19
	identification  goto 20
	input_keyword  goto 21
	function  goto 22
	output_keyword  goto 23
	if_sentence  goto 24
	for_head  goto 25
	repeat_keyword  goto 26
	while_begin_keyword  goto 27
	wait_until_keyword  goto 28
	goto_keyword  goto 29
	gosub_keyword  goto 30
	on_keyword  goto 31
	for_keyword  goto 32
	if_keyword  goto 33


state 27
	sentence : while_begin_keyword . logic_expr sentence_list TOKEN_WHILE_END

	error  shift 46
	TOKEN_ON  shift 47
	TOKEN_NOT  shift 67
	TOKEN_SUB  shift 48
	TOKEN_LEFT_PARENTHESIS  shift 68
	TOKEN_IDENTIFICATION  shift 11
	TOKEN_INTEGER_FUNCTION_NAME  shift 12
	TOKEN_DOUBLE_FUNCTION_NAME  shift 13
	TOKEN_CONST_INT  shift 51
	TOKEN_CONST_DOUBLE  shift 52

	identification  goto 54
	arith_expr  goto 69
	function  goto 56
	logic_expr  goto 70
	relative_expr  goto 71


state 28
	sentence : wait_until_keyword . logic_expr

	error  shift 46
	TOKEN_ON  shift 47
	TOKEN_NOT  shift 67
	TOKEN_SUB  shift 48
	TOKEN_LEFT_PARENTHESIS  shift 68
	TOKEN_IDENTIFICATION  shift 11
	TOKEN_INTEGER_FUNCTION_NAME  shift 12
	TOKEN_DOUBLE_FUNCTION_NAME  shift 13
	TOKEN_CONST_INT  shift 51
	TOKEN_CONST_DOUBLE  shift 52

	identification  goto 54
	arith_expr  goto 69
	function  goto 56
	logic_expr  goto 72
	relative_expr  goto 71


state 29
	sentence : goto_keyword . identification
	sentence : goto_keyword . error

	error  shift 73
	TOKEN_IDENTIFICATION  shift 11

	identification  goto 74


state 30
	sentence : gosub_keyword . identification
	sentence : gosub_keyword . error

	error  shift 75
	TOKEN_IDENTIFICATION  shift 11

	identification  goto 76


state 31
	sentence : on_keyword . arith_expr TOKEN_GOTO identification_list
	sentence : on_keyword . arith_expr TOKEN_GOTO error
	sentence : on_keyword . arith_expr TOKEN_GOSUB identification_list
	sentence : on_keyword . arith_expr TOKEN_GOSUB error
	sentence : on_keyword . arith_expr error
	sentence : on_keyword . TOKEN_BASIC_ERROR TOKEN_GOTO identification
	sentence : on_keyword . TOKEN_BASIC_ERROR TOKEN_GOTO error
	sentence : on_keyword . TOKEN_BASIC_ERROR TOKEN_GOSUB identification
	sentence : on_keyword . TOKEN_BASIC_ERROR TOKEN_GOSUB error
	sentence : on_keyword . TOKEN_BASIC_ERROR error

	error  shift 46
	TOKEN_ON  shift 47
	TOKEN_BASIC_ERROR  shift 77
	TOKEN_SUB  shift 48
	TOKEN_LEFT_PARENTHESIS  shift 49
	TOKEN_IDENTIFICATION  shift 11
	TOKEN_INTEGER_FUNCTION_NAME  shift 12
	TOKEN_DOUBLE_FUNCTION_NAME  shift 13
	TOKEN_CONST_INT  shift 51
	TOKEN_CONST_DOUBLE  shift 52

	identification  goto 54
	arith_expr  goto 78
	function  goto 56


state 32
	for_head : for_keyword . identification
	for_head : for_keyword . error

	error  shift 79
	TOKEN_IDENTIFICATION  shift 11

	identification  goto 80


state 33
	if_sentence : if_keyword . logic_expr TOKEN_THEN
	if_sentence : if_keyword . logic_expr error

	error  shift 46
	TOKEN_ON  shift 47
	TOKEN_NOT  shift 67
	TOKEN_SUB  shift 48
	TOKEN_LEFT_PARENTHESIS  shift 68
	TOKEN_IDENTIFICATION  shift 11
	TOKEN_INTEGER_FUNCTION_NAME  shift 12
	TOKEN_DOUBLE_FUNCTION_NAME  shift 13
	TOKEN_CONST_INT  shift 51
	TOKEN_CONST_DOUBLE  shift 52

	identification  goto 54
	arith_expr  goto 69
	function  goto 56
	logic_expr  goto 81
	relative_expr  goto 71


state 34
	not_empty_sentence_list : not_empty_sentence_list sentence .  (5)

	.  reduce 5


state 35
	sentence : identification error .  (8)

	.  reduce 8


state 36
	sentence : identification TOKEN_COLON .  (7)

	.  reduce 7


state 37
	sentence : identification TOKEN_EQUAL . arith_expr

	error  shift 46
	TOKEN_ON  shift 47
	TOKEN_SUB  shift 48
	TOKEN_LEFT_PARENTHESIS  shift 49
	TOKEN_IDENTIFICATION  shift 11
	TOKEN_INTEGER_FUNCTION_NAME  shift 12
	TOKEN_DOUBLE_FUNCTION_NAME  shift 13
	TOKEN_CONST_INT  shift 51
	TOKEN_CONST_DOUBLE  shift 52

	identification  goto 54
	arith_expr  goto 82
	function  goto 56


state 38
	channel_number_keyword : TOKEN_CHANNEL_NUMBER .  (128)

	.  reduce 128


state 39
	input_item : identification .  (45)

	.  reduce 45


state 40
	sentence : input_keyword input_list .  (9)
	input_list : input_list . TOKEN_COMMA input_item

	TOKEN_COMMA  shift 83
	.  reduce 9


state 41
	input_item : function . parenthese_expr
	input_item : function . parenthese_expr modifier_list
	parenthese_expr : .  (107)

	TOKEN_LEFT_PARENTHESIS  shift 44
	.  reduce 107

	parenthese_expr  goto 84


state 42
	input_keyword : input_keyword channel_number_keyword .  (41)
	input_keyword : input_keyword channel_number_keyword . TOKEN_COMMA

	TOKEN_COMMA  shift 85
	.  reduce 41


state 43
	input_list : input_item .  (43)

	.  reduce 43


state 44
	parenthese_expr : TOKEN_LEFT_PARENTHESIS . TOKEN_RIGHT_PARENTHESIS
	parenthese_expr : TOKEN_LEFT_PARENTHESIS . arith_expr_list TOKEN_RIGHT_PARENTHESIS
	parenthese_expr : TOKEN_LEFT_PARENTHESIS . arith_expr_list error

	error  shift 46
	TOKEN_ON  shift 47
	TOKEN_SUB  shift 48
	TOKEN_RIGHT_PARENTHESIS  shift 86
	TOKEN_LEFT_PARENTHESIS  shift 49
	TOKEN_IDENTIFICATION  shift 11
	TOKEN_INTEGER_FUNCTION_NAME  shift 12
	TOKEN_DOUBLE_FUNCTION_NAME  shift 13
	TOKEN_CONST_INT  shift 51
	TOKEN_CONST_DOUBLE  shift 52

	identification  goto 54
	arith_expr  goto 87
	function  goto 56
	arith_expr_list  goto 88


state 45
	sentence : function parenthese_expr .  (10)
	sentence : function parenthese_expr . modifier_list
	sentence : function parenthese_expr . TOKEN_EQUAL arith_expr
	sentence : function parenthese_expr . modifier_list TOKEN_EQUAL arith_expr

	TOKEN_EQUAL  shift 89
	TOKEN_MODIFY_NAME  shift 90
	.  reduce 10

	modifier_list  goto 91
	modifier  goto 92


state 46
	arith_expr : error .  (92)

	.  reduce 92


state 47
	arith_expr : TOKEN_ON .  (82)

	.  reduce 82


state 48
	arith_expr : TOKEN_SUB . arith_expr

	error  shift 46
	TOKEN_ON  shift 47
	TOKEN_SUB  shift 48
	TOKEN_LEFT_PARENTHESIS  shift 49
	TOKEN_IDENTIFICATION  shift 11
	TOKEN_INTEGER_FUNCTION_NAME  shift 12
	TOKEN_DOUBLE_FUNCTION_NAME  shift 13
	TOKEN_CONST_INT  shift 51
	TOKEN_CONST_DOUBLE  shift 52

	identification  goto 54
	arith_expr  goto 93
	function  goto 56


state 49
	arith_expr : TOKEN_LEFT_PARENTHESIS . arith_expr TOKEN_RIGHT_PARENTHESIS

	error  shift 46
	TOKEN_ON  shift 47
	TOKEN_SUB  shift 48
	TOKEN_LEFT_PARENTHESIS  shift 49
	TOKEN_IDENTIFICATION  shift 11
	TOKEN_INTEGER_FUNCTION_NAME  shift 12
	TOKEN_DOUBLE_FUNCTION_NAME  shift 13
	TOKEN_CONST_INT  shift 51
	TOKEN_CONST_DOUBLE  shift 52

	identification  goto 54
	arith_expr  goto 94
	function  goto 56


state 50
	number_string : TOKEN_NUMBER_CHARACTER .  (127)

	.  reduce 127


state 51
	arith_expr : TOKEN_CONST_INT .  (80)

	.  reduce 80


state 52
	arith_expr : TOKEN_CONST_DOUBLE .  (81)

	.  reduce 81


state 53
	output_item : TOKEN_STRING .  (56)

	.  reduce 56


state 54
	arith_expr : identification .  (83)

	.  reduce 83


state 55
	output_item : arith_expr .  (57)
	arith_expr : arith_expr . TOKEN_ADD arith_expr
	arith_expr : arith_expr . TOKEN_SUB arith_expr
	arith_expr : arith_expr . TOKEN_MUL arith_expr
	arith_expr : arith_expr . TOKEN_DIV arith_expr

	TOKEN_ADD  shift 95
	TOKEN_SUB  shift 96
	TOKEN_MUL  shift 97
	TOKEN_DIV  shift 98
	.  reduce 57


state 56
	arith_expr : function . parenthese_expr
	arith_expr : function . parenthese_expr modifier_list
	parenthese_expr : .  (107)

	TOKEN_LEFT_PARENTHESIS  shift 44
	.  reduce 107

	parenthese_expr  goto 99


state 57
	sentence : output_keyword output_list .  (14)
	output_list : output_list . TOKEN_COMMA output_format
	output_list : output_list . TOKEN_SEMICOLON output_format

	TOKEN_SEMICOLON  shift 100
	TOKEN_COMMA  shift 101
	.  reduce 14


state 58
	output_keyword : output_keyword channel_number_keyword .  (38)
	output_keyword : output_keyword channel_number_keyword . TOKEN_COMMA

	TOKEN_COMMA  shift 102
	.  reduce 38


state 59
	output_list : output_format .  (48)

	.  reduce 48


state 60
	output_format : output_item .  (51)
	output_format : output_item . TOKEN_LEFT_SQUARE_BRACKET arith_expr TOKEN_RIGHT_SQUARE_BRACKET
	output_format : output_item . TOKEN_LEFT_SQUARE_BRACKET arith_expr TOKEN_COMMA arith_expr TOKEN_RIGHT_SQUARE_BRACKET
	output_format : output_item . TOKEN_LEFT_SQUARE_BRACKET arith_expr error
	output_format : output_item . TOKEN_LEFT_SQUARE_BRACKET arith_expr TOKEN_COMMA arith_expr error

	TOKEN_LEFT_SQUARE_BRACKET  shift 103
	.  reduce 51


state 61
	output_item : number_string . TOKEN_LEFT_PARENTHESIS arith_expr TOKEN_RIGHT_PARENTHESIS
	output_item : number_string . error
	output_item : number_string . TOKEN_LEFT_PARENTHESIS arith_expr error

	error  shift 104
	TOKEN_LEFT_PARENTHESIS  shift 105


state 62
	sentence : if_sentence sentence_list . TOKEN_ENDIF
	sentence : if_sentence sentence_list . else_sentence TOKEN_ENDIF

	TOKEN_ELSE  shift 106
	TOKEN_ELSEIF  shift 107
	TOKEN_ENDIF  shift 108

	else_sentence  goto 109
	else_sub_sentence  goto 110


state 63
	for_1 : error .  (66)

	.  reduce 66


state 64
	for_1 : TOKEN_EQUAL . arith_expr

	error  shift 46
	TOKEN_ON  shift 47
	TOKEN_SUB  shift 48
	TOKEN_LEFT_PARENTHESIS  shift 49
	TOKEN_IDENTIFICATION  shift 11
	TOKEN_INTEGER_FUNCTION_NAME  shift 12
	TOKEN_DOUBLE_FUNCTION_NAME  shift 13
	TOKEN_CONST_INT  shift 51
	TOKEN_CONST_DOUBLE  shift 52

	identification  goto 54
	arith_expr  goto 111
	function  goto 56


state 65
	sentence : for_head for_1 . for_2 for_3 sentence_list for_tail

	error  shift 112
	TOKEN_TO  shift 113

	for_2  goto 114


state 66
	sentence : repeat_keyword sentence_list . TOKEN_UNTIL logic_expr

	TOKEN_UNTIL  shift 115


state 67
	logic_expr : TOKEN_NOT . logic_expr

	error  shift 46
	TOKEN_ON  shift 47
	TOKEN_NOT  shift 67
	TOKEN_SUB  shift 48
	TOKEN_LEFT_PARENTHESIS  shift 68
	TOKEN_IDENTIFICATION  shift 11
	TOKEN_INTEGER_FUNCTION_NAME  shift 12
	TOKEN_DOUBLE_FUNCTION_NAME  shift 13
	TOKEN_CONST_INT  shift 51
	TOKEN_CONST_DOUBLE  shift 52

	identification  goto 54
	arith_expr  goto 69
	function  goto 56
	logic_expr  goto 116
	relative_expr  goto 71


state 68
	arith_expr : TOKEN_LEFT_PARENTHESIS . arith_expr TOKEN_RIGHT_PARENTHESIS
	logic_expr : TOKEN_LEFT_PARENTHESIS . logic_expr TOKEN_RIGHT_PARENTHESIS
	logic_expr : TOKEN_LEFT_PARENTHESIS . logic_expr error

	error  shift 46
	TOKEN_ON  shift 47
	TOKEN_NOT  shift 67
	TOKEN_SUB  shift 48
	TOKEN_LEFT_PARENTHESIS  shift 68
	TOKEN_IDENTIFICATION  shift 11
	TOKEN_INTEGER_FUNCTION_NAME  shift 12
	TOKEN_DOUBLE_FUNCTION_NAME  shift 13
	TOKEN_CONST_INT  shift 51
	TOKEN_CONST_DOUBLE  shift 52

	identification  goto 54
	arith_expr  goto 117
	function  goto 56
	logic_expr  goto 118
	relative_expr  goto 71


state 69
	arith_expr : arith_expr . TOKEN_ADD arith_expr
	arith_expr : arith_expr . TOKEN_SUB arith_expr
	arith_expr : arith_expr . TOKEN_MUL arith_expr
	arith_expr : arith_expr . TOKEN_DIV arith_expr
	relative_expr : arith_expr . TOKEN_EQUAL arith_expr
	relative_expr : arith_expr . TOKEN_NOT_EQUAL arith_expr
	relative_expr : arith_expr . TOKEN_GREAT arith_expr
	relative_expr : arith_expr . TOKEN_GREAT_EQUAL arith_expr
	relative_expr : arith_expr . TOKEN_LESS arith_expr
	relative_expr : arith_expr . TOKEN_LESS_EQUAL arith_expr
	relative_expr : arith_expr . error

	error  shift 119
	TOKEN_EQUAL  shift 120
	TOKEN_NOT_EQUAL  shift 121
	TOKEN_GREAT  shift 122
	TOKEN_GREAT_EQUAL  shift 123
	TOKEN_LESS  shift 124
	TOKEN_LESS_EQUAL  shift 125
	TOKEN_ADD  shift 95
	TOKEN_SUB  shift 96
	TOKEN_MUL  shift 97
	TOKEN_DIV  shift 98


state 70
	sentence : while_begin_keyword logic_expr . sentence_list TOKEN_WHILE_END
	logic_expr : logic_expr . TOKEN_AND logic_expr
	logic_expr : logic_expr . TOKEN_OR logic_expr
	logic_expr : logic_expr . TOKEN_XOR logic_expr
	sentence_list : .  (3)

	error  shift 1
	TOKEN_IF  shift 2
	TOKEN_FOR  shift 3
	TOKEN_REPEAT  shift 4
	TOKEN_WHILE_BEGIN  shift 5
	TOKEN_WAIT_UNTIL  shift 6
	TOKEN_ON  shift 7
	TOKEN_GOTO  shift 8
	TOKEN_GOSUB  shift 9
	TOKEN_RETURN  shift 10
	TOKEN_OR  shift 126
	TOKEN_XOR  shift 127
	TOKEN_AND  shift 128
	TOKEN_IDENTIFICATION  shift 11
	TOKEN_INTEGER_FUNCTION_NAME  shift 12
	TOKEN_DOUBLE_FUNCTION_NAME  shift 13
	TOKEN_OUTPUT_NAME  shift 14
	TOKEN_INPUT_NAME  shift 15
	.  reduce 3

	sentence_list  goto 129
	not_empty_sentence_list  goto 18
	sentence  goto 19
	identification  goto 20
	input_keyword  goto 21
	function  goto 22
	output_keyword  goto 23
	if_sentence  goto 24
	for_head  goto 25
	repeat_keyword  goto 26
	while_begin_keyword  goto 27
	wait_until_keyword  goto 28
	goto_keyword  goto 29
	gosub_keyword  goto 30
	on_keyword  goto 31
	for_keyword  goto 32
	if_keyword  goto 33


state 71
	logic_expr : relative_expr .  (100)

	.  reduce 100


state 72
	sentence : wait_until_keyword logic_expr .  (20)
	logic_expr : logic_expr . TOKEN_AND logic_expr
	logic_expr : logic_expr . TOKEN_OR logic_expr
	logic_expr : logic_expr . TOKEN_XOR logic_expr

	TOKEN_OR  shift 126
	TOKEN_XOR  shift 127
	TOKEN_AND  shift 128
	.  reduce 20


state 73
	sentence : goto_keyword error .  (22)

	.  reduce 22


state 74
	sentence : goto_keyword identification .  (21)

	.  reduce 21


state 75
	sentence : gosub_keyword error .  (24)

	.  reduce 24


state 76
	sentence : gosub_keyword identification .  (23)

	.  reduce 23


state 77
	sentence : on_keyword TOKEN_BASIC_ERROR . TOKEN_GOTO identification
	sentence : on_keyword TOKEN_BASIC_ERROR . TOKEN_GOTO error
	sentence : on_keyword TOKEN_BASIC_ERROR . TOKEN_GOSUB identification
	sentence : on_keyword TOKEN_BASIC_ERROR . TOKEN_GOSUB error
	sentence : on_keyword TOKEN_BASIC_ERROR . error

	error  shift 130
	TOKEN_GOTO  shift 131
	TOKEN_GOSUB  shift 132


state 78
	sentence : on_keyword arith_expr . TOKEN_GOTO identification_list
	sentence : on_keyword arith_expr . TOKEN_GOTO error
	sentence : on_keyword arith_expr . TOKEN_GOSUB identification_list
	sentence : on_keyword arith_expr . TOKEN_GOSUB error
	sentence : on_keyword arith_expr . error
	arith_expr : arith_expr . TOKEN_ADD arith_expr
	arith_expr : arith_expr . TOKEN_SUB arith_expr
	arith_expr : arith_expr . TOKEN_MUL arith_expr
	arith_expr : arith_expr . TOKEN_DIV arith_expr

	error  shift 133
	TOKEN_GOTO  shift 134
	TOKEN_GOSUB  shift 135
	TOKEN_ADD  shift 95
	TOKEN_SUB  shift 96
	TOKEN_MUL  shift 97
	TOKEN_DIV  shift 98


state 79
	for_head : for_keyword error .  (64)

	.  reduce 64


state 80
	for_head : for_keyword identification .  (63)

	.  reduce 63


state 81
	if_sentence : if_keyword logic_expr . TOKEN_THEN
	if_sentence : if_keyword logic_expr . error
	logic_expr : logic_expr . TOKEN_AND logic_expr
	logic_expr : logic_expr . TOKEN_OR logic_expr
	logic_expr : logic_expr . TOKEN_XOR logic_expr

	error  shift 136
	TOKEN_THEN  shift 137
	TOKEN_OR  shift 126
	TOKEN_XOR  shift 127
	TOKEN_AND  shift 128


state 82
	sentence : identification TOKEN_EQUAL arith_expr .  (6)
	arith_expr : arith_expr . TOKEN_ADD arith_expr
	arith_expr : arith_expr . TOKEN_SUB arith_expr
	arith_expr : arith_expr . TOKEN_MUL arith_expr
	arith_expr : arith_expr . TOKEN_DIV arith_expr

	TOKEN_ADD  shift 95
	TOKEN_SUB  shift 96
	TOKEN_MUL  shift 97
	TOKEN_DIV  shift 98
	.  reduce 6


state 83
	input_list : input_list TOKEN_COMMA . input_item

	TOKEN_IDENTIFICATION  shift 11
	TOKEN_INTEGER_FUNCTION_NAME  shift 12
	TOKEN_DOUBLE_FUNCTION_NAME  shift 13

	identification  goto 39
	function  goto 41
	input_item  goto 138


state 84
	input_item : function parenthese_expr .  (46)
	input_item : function parenthese_expr . modifier_list

	TOKEN_MODIFY_NAME  shift 90
	.  reduce 46

	modifier_list  goto 139
	modifier  goto 92


state 85
	input_keyword : input_keyword channel_number_keyword TOKEN_COMMA .  (42)

	.  reduce 42


state 86
	parenthese_expr : TOKEN_LEFT_PARENTHESIS TOKEN_RIGHT_PARENTHESIS .  (108)

	.  reduce 108


state 87
	arith_expr : arith_expr . TOKEN_ADD arith_expr
	arith_expr : arith_expr . TOKEN_SUB arith_expr
	arith_expr : arith_expr . TOKEN_MUL arith_expr
	arith_expr : arith_expr . TOKEN_DIV arith_expr
	arith_expr_list : arith_expr .  (111)

	TOKEN_ADD  shift 95
	TOKEN_SUB  shift 96
	TOKEN_MUL  shift 97
	TOKEN_DIV  shift 98
	.  reduce 111


state 88
	parenthese_expr : TOKEN_LEFT_PARENTHESIS arith_expr_list . TOKEN_RIGHT_PARENTHESIS
	parenthese_expr : TOKEN_LEFT_PARENTHESIS arith_expr_list . error
	arith_expr_list : arith_expr_list . TOKEN_COMMA arith_expr

	error  shift 140
	TOKEN_COMMA  shift 141
	TOKEN_RIGHT_PARENTHESIS  shift 142


state 89
	sentence : function parenthese_expr TOKEN_EQUAL . arith_expr

	error  shift 46
	TOKEN_ON  shift 47
	TOKEN_SUB  shift 48
	TOKEN_LEFT_PARENTHESIS  shift 49
	TOKEN_IDENTIFICATION  shift 11
	TOKEN_INTEGER_FUNCTION_NAME  shift 12
	TOKEN_DOUBLE_FUNCTION_NAME  shift 13
	TOKEN_CONST_INT  shift 51
	TOKEN_CONST_DOUBLE  shift 52

	identification  goto 54
	arith_expr  goto 143
	function  goto 56


state 90
	modifier : TOKEN_MODIFY_NAME .  (118)

	.  reduce 118


state 91
	sentence : function parenthese_expr modifier_list .  (11)
	sentence : function parenthese_expr modifier_list . TOKEN_EQUAL arith_expr
	modifier_list : modifier_list . modifier parenthese_expr

	TOKEN_EQUAL  shift 144
	TOKEN_MODIFY_NAME  shift 90
	.  reduce 11

	modifier  goto 145


state 92
	modifier_list : modifier . parenthese_expr
	parenthese_expr : .  (107)

	TOKEN_LEFT_PARENTHESIS  shift 44
	.  reduce 107

	parenthese_expr  goto 146


state 93
	arith_expr : arith_expr . TOKEN_ADD arith_expr
	arith_expr : arith_expr . TOKEN_SUB arith_expr
	arith_expr : arith_expr . TOKEN_MUL arith_expr
	arith_expr : arith_expr . TOKEN_DIV arith_expr
	arith_expr : TOKEN_SUB arith_expr .  (91)

	TOKEN_MUL  shift 97
	TOKEN_DIV  shift 98
	.  reduce 91


state 94
	arith_expr : arith_expr . TOKEN_ADD arith_expr
	arith_expr : arith_expr . TOKEN_SUB arith_expr
	arith_expr : arith_expr . TOKEN_MUL arith_expr
	arith_expr : arith_expr . TOKEN_DIV arith_expr
	arith_expr : TOKEN_LEFT_PARENTHESIS arith_expr . TOKEN_RIGHT_PARENTHESIS

	TOKEN_ADD  shift 95
	TOKEN_SUB  shift 96
	TOKEN_MUL  shift 97
	TOKEN_DIV  shift 98
	TOKEN_RIGHT_PARENTHESIS  shift 147


state 95
	arith_expr : arith_expr TOKEN_ADD . arith_expr

	error  shift 46
	TOKEN_ON  shift 47
	TOKEN_SUB  shift 48
	TOKEN_LEFT_PARENTHESIS  shift 49
	TOKEN_IDENTIFICATION  shift 11
	TOKEN_INTEGER_FUNCTION_NAME  shift 12
	TOKEN_DOUBLE_FUNCTION_NAME  shift 13
	TOKEN_CONST_INT  shift 51
	TOKEN_CONST_DOUBLE  shift 52

	identification  goto 54
	arith_expr  goto 148
	function  goto 56


state 96
	arith_expr : arith_expr TOKEN_SUB . arith_expr

	error  shift 46
	TOKEN_ON  shift 47
	TOKEN_SUB  shift 48
	TOKEN_LEFT_PARENTHESIS  shift 49
	TOKEN_IDENTIFICATION  shift 11
	TOKEN_INTEGER_FUNCTION_NAME  shift 12
	TOKEN_DOUBLE_FUNCTION_NAME  shift 13
	TOKEN_CONST_INT  shift 51
	TOKEN_CONST_DOUBLE  shift 52

	identification  goto 54
	arith_expr  goto 149
	function  goto 56


state 97
	arith_expr : arith_expr TOKEN_MUL . arith_expr

	error  shift 46
	TOKEN_ON  shift 47
	TOKEN_SUB  shift 48
	TOKEN_LEFT_PARENTHESIS  shift 49
	TOKEN_IDENTIFICATION  shift 11
	TOKEN_INTEGER_FUNCTION_NAME  shift 12
	TOKEN_DOUBLE_FUNCTION_NAME  shift 13
	TOKEN_CONST_INT  shift 51
	TOKEN_CONST_DOUBLE  shift 52

	identification  goto 54
	arith_expr  goto 150
	function  goto 56


state 98
	arith_expr : arith_expr TOKEN_DIV . arith_expr

	error  shift 46
	TOKEN_ON  shift 47
	TOKEN_SUB  shift 48
	TOKEN_LEFT_PARENTHESIS  shift 49
	TOKEN_IDENTIFICATION  shift 11
	TOKEN_INTEGER_FUNCTION_NAME  shift 12
	TOKEN_DOUBLE_FUNCTION_NAME  shift 13
	TOKEN_CONST_INT  shift 51
	TOKEN_CONST_DOUBLE  shift 52

	identification  goto 54
	arith_expr  goto 151
	function  goto 56


state 99
	arith_expr : function parenthese_expr .  (84)
	arith_expr : function parenthese_expr . modifier_list

	TOKEN_MODIFY_NAME  shift 90
	.  reduce 84

	modifier_list  goto 152
	modifier  goto 92


state 100
	output_list : output_list TOKEN_SEMICOLON . output_format

	error  shift 46
	TOKEN_ON  shift 47
	TOKEN_SUB  shift 48
	TOKEN_LEFT_PARENTHESIS  shift 49
	TOKEN_NUMBER_CHARACTER  shift 50
	TOKEN_IDENTIFICATION  shift 11
	TOKEN_INTEGER_FUNCTION_NAME  shift 12
	TOKEN_DOUBLE_FUNCTION_NAME  shift 13
	TOKEN_CONST_INT  shift 51
	TOKEN_CONST_DOUBLE  shift 52
	TOKEN_STRING  shift 53

	identification  goto 54
	arith_expr  goto 55
	function  goto 56
	output_format  goto 153
	output_item  goto 60
	number_string  goto 61


state 101
	output_list : output_list TOKEN_COMMA . output_format

	error  shift 46
	TOKEN_ON  shift 47
	TOKEN_SUB  shift 48
	TOKEN_LEFT_PARENTHESIS  shift 49
	TOKEN_NUMBER_CHARACTER  shift 50
	TOKEN_IDENTIFICATION  shift 11
	TOKEN_INTEGER_FUNCTION_NAME  shift 12
	TOKEN_DOUBLE_FUNCTION_NAME  shift 13
	TOKEN_CONST_INT  shift 51
	TOKEN_CONST_DOUBLE  shift 52
	TOKEN_STRING  shift 53

	identification  goto 54
	arith_expr  goto 55
	function  goto 56
	output_format  goto 154
	output_item  goto 60
	number_string  goto 61


state 102
	output_keyword : output_keyword channel_number_keyword TOKEN_COMMA .  (39)

	.  reduce 39


state 103
	output_format : output_item TOKEN_LEFT_SQUARE_BRACKET . arith_expr TOKEN_RIGHT_SQUARE_BRACKET
	output_format : output_item TOKEN_LEFT_SQUARE_BRACKET . arith_expr TOKEN_COMMA arith_expr TOKEN_RIGHT_SQUARE_BRACKET
	output_format : output_item TOKEN_LEFT_SQUARE_BRACKET . arith_expr error
	output_format : output_item TOKEN_LEFT_SQUARE_BRACKET . arith_expr TOKEN_COMMA arith_expr error

	error  shift 46
	TOKEN_ON  shift 47
	TOKEN_SUB  shift 48
	TOKEN_LEFT_PARENTHESIS  shift 49
	TOKEN_IDENTIFICATION  shift 11
	TOKEN_INTEGER_FUNCTION_NAME  shift 12
	TOKEN_DOUBLE_FUNCTION_NAME  shift 13
	TOKEN_CONST_INT  shift 51
	TOKEN_CONST_DOUBLE  shift 52

	identification  goto 54
	arith_expr  goto 155
	function  goto 56


state 104
	output_item : number_string error .  (59)

	.  reduce 59


state 105
	output_item : number_string TOKEN_LEFT_PARENTHESIS . arith_expr TOKEN_RIGHT_PARENTHESIS
	output_item : number_string TOKEN_LEFT_PARENTHESIS . arith_expr error

	error  shift 46
	TOKEN_ON  shift 47
	TOKEN_SUB  shift 48
	TOKEN_LEFT_PARENTHESIS  shift 49
	TOKEN_IDENTIFICATION  shift 11
	TOKEN_INTEGER_FUNCTION_NAME  shift 12
	TOKEN_DOUBLE_FUNCTION_NAME  shift 13
	TOKEN_CONST_INT  shift 51
	TOKEN_CONST_DOUBLE  shift 52

	identification  goto 54
	arith_expr  goto 156
	function  goto 56


state 106
	else_sentence : TOKEN_ELSE . sentence_list
	sentence_list : .  (3)

	error  shift 1
	TOKEN_IF  shift 2
	TOKEN_FOR  shift 3
	TOKEN_REPEAT  shift 4
	TOKEN_WHILE_BEGIN  shift 5
	TOKEN_WAIT_UNTIL  shift 6
	TOKEN_ON  shift 7
	TOKEN_GOTO  shift 8
	TOKEN_GOSUB  shift 9
	TOKEN_RETURN  shift 10
	TOKEN_IDENTIFICATION  shift 11
	TOKEN_INTEGER_FUNCTION_NAME  shift 12
	TOKEN_DOUBLE_FUNCTION_NAME  shift 13
	TOKEN_OUTPUT_NAME  shift 14
	TOKEN_INPUT_NAME  shift 15
	.  reduce 3

	sentence_list  goto 157
	not_empty_sentence_list  goto 18
	sentence  goto 19
	identification  goto 20
	input_keyword  goto 21
	function  goto 22
	output_keyword  goto 23
	if_sentence  goto 24
	for_head  goto 25
	repeat_keyword  goto 26
	while_begin_keyword  goto 27
	wait_until_keyword  goto 28
	goto_keyword  goto 29
	gosub_keyword  goto 30
	on_keyword  goto 31
	for_keyword  goto 32
	if_keyword  goto 33


state 107
	else_sub_sentence : TOKEN_ELSEIF . logic_expr TOKEN_THEN
	else_sub_sentence : TOKEN_ELSEIF . logic_expr error

	error  shift 46
	TOKEN_ON  shift 47
	TOKEN_NOT  shift 67
	TOKEN_SUB  shift 48
	TOKEN_LEFT_PARENTHESIS  shift 68
	TOKEN_IDENTIFICATION  shift 11
	TOKEN_INTEGER_FUNCTION_NAME  shift 12
	TOKEN_DOUBLE_FUNCTION_NAME  shift 13
	TOKEN_CONST_INT  shift 51
	TOKEN_CONST_DOUBLE  shift 52

	identification  goto 54
	arith_expr  goto 69
	function  goto 56
	logic_expr  goto 158
	relative_expr  goto 71


state 108
	sentence : if_sentence sentence_list TOKEN_ENDIF .  (15)

	.  reduce 15


state 109
	sentence : if_sentence sentence_list else_sentence . TOKEN_ENDIF

	TOKEN_ENDIF  shift 159


state 110
	else_sentence : else_sub_sentence . sentence_list
	else_sentence : else_sub_sentence . sentence_list else_sentence
	sentence_list : .  (3)

	error  shift 1
	TOKEN_IF  shift 2
	TOKEN_FOR  shift 3
	TOKEN_REPEAT  shift 4
	TOKEN_WHILE_BEGIN  shift 5
	TOKEN_WAIT_UNTIL  shift 6
	TOKEN_ON  shift 7
	TOKEN_GOTO  shift 8
	TOKEN_GOSUB  shift 9
	TOKEN_RETURN  shift 10
	TOKEN_IDENTIFICATION  shift 11
	TOKEN_INTEGER_FUNCTION_NAME  shift 12
	TOKEN_DOUBLE_FUNCTION_NAME  shift 13
	TOKEN_OUTPUT_NAME  shift 14
	TOKEN_INPUT_NAME  shift 15
	.  reduce 3

	sentence_list  goto 160
	not_empty_sentence_list  goto 18
	sentence  goto 19
	identification  goto 20
	input_keyword  goto 21
	function  goto 22
	output_keyword  goto 23
	if_sentence  goto 24
	for_head  goto 25
	repeat_keyword  goto 26
	while_begin_keyword  goto 27
	wait_until_keyword  goto 28
	goto_keyword  goto 29
	gosub_keyword  goto 30
	on_keyword  goto 31
	for_keyword  goto 32
	if_keyword  goto 33


state 111
	for_1 : TOKEN_EQUAL arith_expr .  (65)
	arith_expr : arith_expr . TOKEN_ADD arith_expr
	arith_expr : arith_expr . TOKEN_SUB arith_expr
	arith_expr : arith_expr . TOKEN_MUL arith_expr
	arith_expr : arith_expr . TOKEN_DIV arith_expr

	TOKEN_ADD  shift 95
	TOKEN_SUB  shift 96
	TOKEN_MUL  shift 97
	TOKEN_DIV  shift 98
	.  reduce 65


state 112
	for_2 : error .  (68)

	.  reduce 68


state 113
	for_2 : TOKEN_TO . arith_expr

	error  shift 46
	TOKEN_ON  shift 47
	TOKEN_SUB  shift 48
	TOKEN_LEFT_PARENTHESIS  shift 49
	TOKEN_IDENTIFICATION  shift 11
	TOKEN_INTEGER_FUNCTION_NAME  shift 12
	TOKEN_DOUBLE_FUNCTION_NAME  shift 13
	TOKEN_CONST_INT  shift 51
	TOKEN_CONST_DOUBLE  shift 52

	identification  goto 54
	arith_expr  goto 161
	function  goto 56


state 114
	sentence : for_head for_1 for_2 . for_3 sentence_list for_tail
	for_3 : .  (70)

	TOKEN_STEP  shift 162
	.  reduce 70

	for_3  goto 163


state 115
	sentence : repeat_keyword sentence_list TOKEN_UNTIL . logic_expr

	error  shift 46
	TOKEN_ON  shift 47
	TOKEN_NOT  shift 67
	TOKEN_SUB  shift 48
	TOKEN_LEFT_PARENTHESIS  shift 68
	TOKEN_IDENTIFICATION  shift 11
	TOKEN_INTEGER_FUNCTION_NAME  shift 12
	TOKEN_DOUBLE_FUNCTION_NAME  shift 13
	TOKEN_CONST_INT  shift 51
	TOKEN_CONST_DOUBLE  shift 52

	identification  goto 54
	arith_expr  goto 69
	function  goto 56
	logic_expr  goto 164
	relative_expr  goto 71


state 116
	logic_expr : logic_expr . TOKEN_AND logic_expr
	logic_expr : logic_expr . TOKEN_OR logic_expr
	logic_expr : logic_expr . TOKEN_XOR logic_expr
	logic_expr : TOKEN_NOT logic_expr .  (104)

	.  reduce 104


state 117
	arith_expr : arith_expr . TOKEN_ADD arith_expr
	arith_expr : arith_expr . TOKEN_SUB arith_expr
	arith_expr : arith_expr . TOKEN_MUL arith_expr
	arith_expr : arith_expr . TOKEN_DIV arith_expr
	arith_expr : TOKEN_LEFT_PARENTHESIS arith_expr . TOKEN_RIGHT_PARENTHESIS
	relative_expr : arith_expr . TOKEN_EQUAL arith_expr
	relative_expr : arith_expr . TOKEN_NOT_EQUAL arith_expr
	relative_expr : arith_expr . TOKEN_GREAT arith_expr
	relative_expr : arith_expr . TOKEN_GREAT_EQUAL arith_expr
	relative_expr : arith_expr . TOKEN_LESS arith_expr
	relative_expr : arith_expr . TOKEN_LESS_EQUAL arith_expr
	relative_expr : arith_expr . error

	error  shift 119
	TOKEN_EQUAL  shift 120
	TOKEN_NOT_EQUAL  shift 121
	TOKEN_GREAT  shift 122
	TOKEN_GREAT_EQUAL  shift 123
	TOKEN_LESS  shift 124
	TOKEN_LESS_EQUAL  shift 125
	TOKEN_ADD  shift 95
	TOKEN_SUB  shift 96
	TOKEN_MUL  shift 97
	TOKEN_DIV  shift 98
	TOKEN_RIGHT_PARENTHESIS  shift 147


state 118
	logic_expr : logic_expr . TOKEN_AND logic_expr
	logic_expr : logic_expr . TOKEN_OR logic_expr
	logic_expr : logic_expr . TOKEN_XOR logic_expr
	logic_expr : TOKEN_LEFT_PARENTHESIS logic_expr . TOKEN_RIGHT_PARENTHESIS
	logic_expr : TOKEN_LEFT_PARENTHESIS logic_expr . error

	error  shift 165
	TOKEN_OR  shift 126
	TOKEN_XOR  shift 127
	TOKEN_AND  shift 128
	TOKEN_RIGHT_PARENTHESIS  shift 166


state 119
	relative_expr : arith_expr error .  (99)

	.  reduce 99


state 120
	relative_expr : arith_expr TOKEN_EQUAL . arith_expr

	error  shift 46
	TOKEN_ON  shift 47
	TOKEN_SUB  shift 48
	TOKEN_LEFT_PARENTHESIS  shift 49
	TOKEN_IDENTIFICATION  shift 11
	TOKEN_INTEGER_FUNCTION_NAME  shift 12
	TOKEN_DOUBLE_FUNCTION_NAME  shift 13
	TOKEN_CONST_INT  shift 51
	TOKEN_CONST_DOUBLE  shift 52

	identification  goto 54
	arith_expr  goto 167
	function  goto 56


state 121
	relative_expr : arith_expr TOKEN_NOT_EQUAL . arith_expr

	error  shift 46
	TOKEN_ON  shift 47
	TOKEN_SUB  shift 48
	TOKEN_LEFT_PARENTHESIS  shift 49
	TOKEN_IDENTIFICATION  shift 11
	TOKEN_INTEGER_FUNCTION_NAME  shift 12
	TOKEN_DOUBLE_FUNCTION_NAME  shift 13
	TOKEN_CONST_INT  shift 51
	TOKEN_CONST_DOUBLE  shift 52

	identification  goto 54
	arith_expr  goto 168
	function  goto 56


state 122
	relative_expr : arith_expr TOKEN_GREAT . arith_expr

	error  shift 46
	TOKEN_ON  shift 47
	TOKEN_SUB  shift 48
	TOKEN_LEFT_PARENTHESIS  shift 49
	TOKEN_IDENTIFICATION  shift 11
	TOKEN_INTEGER_FUNCTION_NAME  shift 12
	TOKEN_DOUBLE_FUNCTION_NAME  shift 13
	TOKEN_CONST_INT  shift 51
	TOKEN_CONST_DOUBLE  shift 52

	identification  goto 54
	arith_expr  goto 169
	function  goto 56


state 123
	relative_expr : arith_expr TOKEN_GREAT_EQUAL . arith_expr

	error  shift 46
	TOKEN_ON  shift 47
	TOKEN_SUB  shift 48
	TOKEN_LEFT_PARENTHESIS  shift 49
	TOKEN_IDENTIFICATION  shift 11
	TOKEN_INTEGER_FUNCTION_NAME  shift 12
	TOKEN_DOUBLE_FUNCTION_NAME  shift 13
	TOKEN_CONST_INT  shift 51
	TOKEN_CONST_DOUBLE  shift 52

	identification  goto 54
	arith_expr  goto 170
	function  goto 56


state 124
	relative_expr : arith_expr TOKEN_LESS . arith_expr

	error  shift 46
	TOKEN_ON  shift 47
	TOKEN_SUB  shift 48
	TOKEN_LEFT_PARENTHESIS  shift 49
	TOKEN_IDENTIFICATION  shift 11
	TOKEN_INTEGER_FUNCTION_NAME  shift 12
	TOKEN_DOUBLE_FUNCTION_NAME  shift 13
	TOKEN_CONST_INT  shift 51
	TOKEN_CONST_DOUBLE  shift 52

	identification  goto 54
	arith_expr  goto 171
	function  goto 56


state 125
	relative_expr : arith_expr TOKEN_LESS_EQUAL . arith_expr

	error  shift 46
	TOKEN_ON  shift 47
	TOKEN_SUB  shift 48
	TOKEN_LEFT_PARENTHESIS  shift 49
	TOKEN_IDENTIFICATION  shift 11
	TOKEN_INTEGER_FUNCTION_NAME  shift 12
	TOKEN_DOUBLE_FUNCTION_NAME  shift 13
	TOKEN_CONST_INT  shift 51
	TOKEN_CONST_DOUBLE  shift 52

	identification  goto 54
	arith_expr  goto 172
	function  goto 56


state 126
	logic_expr : logic_expr TOKEN_OR . logic_expr

	error  shift 46
	TOKEN_ON  shift 47
	TOKEN_NOT  shift 67
	TOKEN_SUB  shift 48
	TOKEN_LEFT_PARENTHESIS  shift 68
	TOKEN_IDENTIFICATION  shift 11
	TOKEN_INTEGER_FUNCTION_NAME  shift 12
	TOKEN_DOUBLE_FUNCTION_NAME  shift 13
	TOKEN_CONST_INT  shift 51
	TOKEN_CONST_DOUBLE  shift 52

	identification  goto 54
	arith_expr  goto 69
	function  goto 56
	logic_expr  goto 173
	relative_expr  goto 71


state 127
	logic_expr : logic_expr TOKEN_XOR . logic_expr

	error  shift 46
	TOKEN_ON  shift 47
	TOKEN_NOT  shift 67
	TOKEN_SUB  shift 48
	TOKEN_LEFT_PARENTHESIS  shift 68
	TOKEN_IDENTIFICATION  shift 11
	TOKEN_INTEGER_FUNCTION_NAME  shift 12
	TOKEN_DOUBLE_FUNCTION_NAME  shift 13
	TOKEN_CONST_INT  shift 51
	TOKEN_CONST_DOUBLE  shift 52

	identification  goto 54
	arith_expr  goto 69
	function  goto 56
	logic_expr  goto 174
	relative_expr  goto 71


state 128
	logic_expr : logic_expr TOKEN_AND . logic_expr

	error  shift 46
	TOKEN_ON  shift 47
	TOKEN_NOT  shift 67
	TOKEN_SUB  shift 48
	TOKEN_LEFT_PARENTHESIS  shift 68
	TOKEN_IDENTIFICATION  shift 11
	TOKEN_INTEGER_FUNCTION_NAME  shift 12
	TOKEN_DOUBLE_FUNCTION_NAME  shift 13
	TOKEN_CONST_INT  shift 51
	TOKEN_CONST_DOUBLE  shift 52

	identification  goto 54
	arith_expr  goto 69
	function  goto 56
	logic_expr  goto 175
	relative_expr  goto 71


state 129
	sentence : while_begin_keyword logic_expr sentence_list . TOKEN_WHILE_END

	TOKEN_WHILE_END  shift 176


state 130
	sentence : on_keyword TOKEN_BASIC_ERROR error .  (34)

	.  reduce 34


state 131
	sentence : on_keyword TOKEN_BASIC_ERROR TOKEN_GOTO . identification
	sentence : on_keyword TOKEN_BASIC_ERROR TOKEN_GOTO . error

	error  shift 177
	TOKEN_IDENTIFICATION  shift 11

	identification  goto 178


state 132
	sentence : on_keyword TOKEN_BASIC_ERROR TOKEN_GOSUB . identification
	sentence : on_keyword TOKEN_BASIC_ERROR TOKEN_GOSUB . error

	error  shift 179
	TOKEN_IDENTIFICATION  shift 11

	identification  goto 180


state 133
	sentence : on_keyword arith_expr error .  (29)

	.  reduce 29


state 134
	sentence : on_keyword arith_expr TOKEN_GOTO . identification_list
	sentence : on_keyword arith_expr TOKEN_GOTO . error

	error  shift 181
	TOKEN_IDENTIFICATION  shift 11

	identification  goto 182
	identification_list  goto 183


state 135
	sentence : on_keyword arith_expr TOKEN_GOSUB . identification_list
	sentence : on_keyword arith_expr TOKEN_GOSUB . error

	error  shift 184
	TOKEN_IDENTIFICATION  shift 11

	identification  goto 182
	identification_list  goto 185


state 136
	if_sentence : if_keyword logic_expr error .  (74)

	.  reduce 74


state 137
	if_sentence : if_keyword logic_expr TOKEN_THEN .  (73)

	.  reduce 73


state 138
	input_list : input_list TOKEN_COMMA input_item .  (44)

	.  reduce 44


state 139
	input_item : function parenthese_expr modifier_list .  (47)
	modifier_list : modifier_list . modifier parenthese_expr

	TOKEN_MODIFY_NAME  shift 90
	.  reduce 47

	modifier  goto 145


state 140
	parenthese_expr : TOKEN_LEFT_PARENTHESIS arith_expr_list error .  (110)

	.  reduce 110


state 141
	arith_expr_list : arith_expr_list TOKEN_COMMA . arith_expr

	error  shift 46
	TOKEN_ON  shift 47
	TOKEN_SUB  shift 48
	TOKEN_LEFT_PARENTHESIS  shift 49
	TOKEN_IDENTIFICATION  shift 11
	TOKEN_INTEGER_FUNCTION_NAME  shift 12
	TOKEN_DOUBLE_FUNCTION_NAME  shift 13
	TOKEN_CONST_INT  shift 51
	TOKEN_CONST_DOUBLE  shift 52

	identification  goto 54
	arith_expr  goto 186
	function  goto 56


state 142
	parenthese_expr : TOKEN_LEFT_PARENTHESIS arith_expr_list TOKEN_RIGHT_PARENTHESIS .  (109)

	.  reduce 109


state 143
	sentence : function parenthese_expr TOKEN_EQUAL arith_expr .  (12)
	arith_expr : arith_expr . TOKEN_ADD arith_expr
	arith_expr : arith_expr . TOKEN_SUB arith_expr
	arith_expr : arith_expr . TOKEN_MUL arith_expr
	arith_expr : arith_expr . TOKEN_DIV arith_expr

	TOKEN_ADD  shift 95
	TOKEN_SUB  shift 96
	TOKEN_MUL  shift 97
	TOKEN_DIV  shift 98
	.  reduce 12


state 144
	sentence : function parenthese_expr modifier_list TOKEN_EQUAL . arith_expr

	error  shift 46
	TOKEN_ON  shift 47
	TOKEN_SUB  shift 48
	TOKEN_LEFT_PARENTHESIS  shift 49
	TOKEN_IDENTIFICATION  shift 11
	TOKEN_INTEGER_FUNCTION_NAME  shift 12
	TOKEN_DOUBLE_FUNCTION_NAME  shift 13
	TOKEN_CONST_INT  shift 51
	TOKEN_CONST_DOUBLE  shift 52

	identification  goto 54
	arith_expr  goto 187
	function  goto 56


state 145
	modifier_list : modifier_list modifier . parenthese_expr
	parenthese_expr : .  (107)

	TOKEN_LEFT_PARENTHESIS  shift 44
	.  reduce 107

	parenthese_expr  goto 188


state 146
	modifier_list : modifier parenthese_expr .  (61)

	.  reduce 61


state 147
	arith_expr : TOKEN_LEFT_PARENTHESIS arith_expr TOKEN_RIGHT_PARENTHESIS .  (90)

	.  reduce 90


state 148
	arith_expr : arith_expr TOKEN_ADD arith_expr .  (86)
	arith_expr : arith_expr . TOKEN_ADD arith_expr
	arith_expr : arith_expr . TOKEN_SUB arith_expr
	arith_expr : arith_expr . TOKEN_MUL arith_expr
	arith_expr : arith_expr . TOKEN_DIV arith_expr

	TOKEN_MUL  shift 97
	TOKEN_DIV  shift 98
	.  reduce 86


state 149
	arith_expr : arith_expr . TOKEN_ADD arith_expr
	arith_expr : arith_expr TOKEN_SUB arith_expr .  (87)
	arith_expr : arith_expr . TOKEN_SUB arith_expr
	arith_expr : arith_expr . TOKEN_MUL arith_expr
	arith_expr : arith_expr . TOKEN_DIV arith_expr

	TOKEN_MUL  shift 97
	TOKEN_DIV  shift 98
	.  reduce 87


state 150
	arith_expr : arith_expr . TOKEN_ADD arith_expr
	arith_expr : arith_expr . TOKEN_SUB arith_expr
	arith_expr : arith_expr TOKEN_MUL arith_expr .  (88)
	arith_expr : arith_expr . TOKEN_MUL arith_expr
	arith_expr : arith_expr . TOKEN_DIV arith_expr

	.  reduce 88


state 151
	arith_expr : arith_expr . TOKEN_ADD arith_expr
	arith_expr : arith_expr . TOKEN_SUB arith_expr
	arith_expr : arith_expr . TOKEN_MUL arith_expr
	arith_expr : arith_expr TOKEN_DIV arith_expr .  (89)
	arith_expr : arith_expr . TOKEN_DIV arith_expr

	.  reduce 89


state 152
	modifier_list : modifier_list . modifier parenthese_expr
	arith_expr : function parenthese_expr modifier_list .  (85)

	TOKEN_MODIFY_NAME  shift 90
	.  reduce 85

	modifier  goto 145


state 153
	output_list : output_list TOKEN_SEMICOLON output_format .  (50)

	.  reduce 50


state 154
	output_list : output_list TOKEN_COMMA output_format .  (49)

	.  reduce 49


state 155
	output_format : output_item TOKEN_LEFT_SQUARE_BRACKET arith_expr . TOKEN_RIGHT_SQUARE_BRACKET
	output_format : output_item TOKEN_LEFT_SQUARE_BRACKET arith_expr . TOKEN_COMMA arith_expr TOKEN_RIGHT_SQUARE_BRACKET
	output_format : output_item TOKEN_LEFT_SQUARE_BRACKET arith_expr . error
	output_format : output_item TOKEN_LEFT_SQUARE_BRACKET arith_expr . TOKEN_COMMA arith_expr error
	arith_expr : arith_expr . TOKEN_ADD arith_expr
	arith_expr : arith_expr . TOKEN_SUB arith_expr
	arith_expr : arith_expr . TOKEN_MUL arith_expr
	arith_expr : arith_expr . TOKEN_DIV arith_expr

	error  shift 189
	TOKEN_COMMA  shift 190
	TOKEN_ADD  shift 95
	TOKEN_SUB  shift 96
	TOKEN_MUL  shift 97
	TOKEN_DIV  shift 98
	TOKEN_RIGHT_SQUARE_BRACKET  shift 191


state 156
	output_item : number_string TOKEN_LEFT_PARENTHESIS arith_expr . TOKEN_RIGHT_PARENTHESIS
	output_item : number_string TOKEN_LEFT_PARENTHESIS arith_expr . error
	arith_expr : arith_expr . TOKEN_ADD arith_expr
	arith_expr : arith_expr . TOKEN_SUB arith_expr
	arith_expr : arith_expr . TOKEN_MUL arith_expr
	arith_expr : arith_expr . TOKEN_DIV arith_expr

	error  shift 192
	TOKEN_ADD  shift 95
	TOKEN_SUB  shift 96
	TOKEN_MUL  shift 97
	TOKEN_DIV  shift 98
	TOKEN_RIGHT_PARENTHESIS  shift 193


state 157
	else_sentence : TOKEN_ELSE sentence_list .  (75)

	.  reduce 75


state 158
	else_sub_sentence : TOKEN_ELSEIF logic_expr . TOKEN_THEN
	else_sub_sentence : TOKEN_ELSEIF logic_expr . error
	logic_expr : logic_expr . TOKEN_AND logic_expr
	logic_expr : logic_expr . TOKEN_OR logic_expr
	logic_expr : logic_expr . TOKEN_XOR logic_expr

	error  shift 194
	TOKEN_THEN  shift 195
	TOKEN_OR  shift 126
	TOKEN_XOR  shift 127
	TOKEN_AND  shift 128


state 159
	sentence : if_sentence sentence_list else_sentence TOKEN_ENDIF .  (16)

	.  reduce 16


state 160
	else_sentence : else_sub_sentence sentence_list .  (76)
	else_sentence : else_sub_sentence sentence_list . else_sentence

	TOKEN_ELSE  shift 106
	TOKEN_ELSEIF  shift 107
	.  reduce 76

	else_sentence  goto 196
	else_sub_sentence  goto 110


state 161
	for_2 : TOKEN_TO arith_expr .  (67)
	arith_expr : arith_expr . TOKEN_ADD arith_expr
	arith_expr : arith_expr . TOKEN_SUB arith_expr
	arith_expr : arith_expr . TOKEN_MUL arith_expr
	arith_expr : arith_expr . TOKEN_DIV arith_expr

	TOKEN_ADD  shift 95
	TOKEN_SUB  shift 96
	TOKEN_MUL  shift 97
	TOKEN_DIV  shift 98
	.  reduce 67


state 162
	for_3 : TOKEN_STEP . arith_expr

	error  shift 46
	TOKEN_ON  shift 47
	TOKEN_SUB  shift 48
	TOKEN_LEFT_PARENTHESIS  shift 49
	TOKEN_IDENTIFICATION  shift 11
	TOKEN_INTEGER_FUNCTION_NAME  shift 12
	TOKEN_DOUBLE_FUNCTION_NAME  shift 13
	TOKEN_CONST_INT  shift 51
	TOKEN_CONST_DOUBLE  shift 52

	identification  goto 54
	arith_expr  goto 197
	function  goto 56


state 163
	sentence : for_head for_1 for_2 for_3 . sentence_list for_tail
	sentence_list : .  (3)

	error  shift 1
	TOKEN_IF  shift 2
	TOKEN_FOR  shift 3
	TOKEN_REPEAT  shift 4
	TOKEN_WHILE_BEGIN  shift 5
	TOKEN_WAIT_UNTIL  shift 6
	TOKEN_ON  shift 7
	TOKEN_GOTO  shift 8
	TOKEN_GOSUB  shift 9
	TOKEN_RETURN  shift 10
	TOKEN_IDENTIFICATION  shift 11
	TOKEN_INTEGER_FUNCTION_NAME  shift 12
	TOKEN_DOUBLE_FUNCTION_NAME  shift 13
	TOKEN_OUTPUT_NAME  shift 14
	TOKEN_INPUT_NAME  shift 15
	.  reduce 3

	sentence_list  goto 198
	not_empty_sentence_list  goto 18
	sentence  goto 19
	identification  goto 20
	input_keyword  goto 21
	function  goto 22
	output_keyword  goto 23
	if_sentence  goto 24
	for_head  goto 25
	repeat_keyword  goto 26
	while_begin_keyword  goto 27
	wait_until_keyword  goto 28
	goto_keyword  goto 29
	gosub_keyword  goto 30
	on_keyword  goto 31
	for_keyword  goto 32
	if_keyword  goto 33


state 164
	sentence : repeat_keyword sentence_list TOKEN_UNTIL logic_expr .  (18)
	logic_expr : logic_expr . TOKEN_AND logic_expr
	logic_expr : logic_expr . TOKEN_OR logic_expr
	logic_expr : logic_expr . TOKEN_XOR logic_expr

	TOKEN_OR  shift 126
	TOKEN_XOR  shift 127
	TOKEN_AND  shift 128
	.  reduce 18


state 165
	logic_expr : TOKEN_LEFT_PARENTHESIS logic_expr error .  (106)

	.  reduce 106


state 166
	logic_expr : TOKEN_LEFT_PARENTHESIS logic_expr TOKEN_RIGHT_PARENTHESIS .  (105)

	.  reduce 105


state 167
	arith_expr : arith_expr . TOKEN_ADD arith_expr
	arith_expr : arith_expr . TOKEN_SUB arith_expr
	arith_expr : arith_expr . TOKEN_MUL arith_expr
	arith_expr : arith_expr . TOKEN_DIV arith_expr
	relative_expr : arith_expr TOKEN_EQUAL arith_expr .  (93)

	TOKEN_ADD  shift 95
	TOKEN_SUB  shift 96
	TOKEN_MUL  shift 97
	TOKEN_DIV  shift 98
	.  reduce 93


state 168
	arith_expr : arith_expr . TOKEN_ADD arith_expr
	arith_expr : arith_expr . TOKEN_SUB arith_expr
	arith_expr : arith_expr . TOKEN_MUL arith_expr
	arith_expr : arith_expr . TOKEN_DIV arith_expr
	relative_expr : arith_expr TOKEN_NOT_EQUAL arith_expr .  (94)

	TOKEN_ADD  shift 95
	TOKEN_SUB  shift 96
	TOKEN_MUL  shift 97
	TOKEN_DIV  shift 98
	.  reduce 94


state 169
	arith_expr : arith_expr . TOKEN_ADD arith_expr
	arith_expr : arith_expr . TOKEN_SUB arith_expr
	arith_expr : arith_expr . TOKEN_MUL arith_expr
	arith_expr : arith_expr . TOKEN_DIV arith_expr
	relative_expr : arith_expr TOKEN_GREAT arith_expr .  (95)

	TOKEN_ADD  shift 95
	TOKEN_SUB  shift 96
	TOKEN_MUL  shift 97
	TOKEN_DIV  shift 98
	.  reduce 95


state 170
	arith_expr : arith_expr . TOKEN_ADD arith_expr
	arith_expr : arith_expr . TOKEN_SUB arith_expr
	arith_expr : arith_expr . TOKEN_MUL arith_expr
	arith_expr : arith_expr . TOKEN_DIV arith_expr
	relative_expr : arith_expr TOKEN_GREAT_EQUAL arith_expr .  (96)

	TOKEN_ADD  shift 95
	TOKEN_SUB  shift 96
	TOKEN_MUL  shift 97
	TOKEN_DIV  shift 98
	.  reduce 96


state 171
	arith_expr : arith_expr . TOKEN_ADD arith_expr
	arith_expr : arith_expr . TOKEN_SUB arith_expr
	arith_expr : arith_expr . TOKEN_MUL arith_expr
	arith_expr : arith_expr . TOKEN_DIV arith_expr
	relative_expr : arith_expr TOKEN_LESS arith_expr .  (97)

	TOKEN_ADD  shift 95
	TOKEN_SUB  shift 96
	TOKEN_MUL  shift 97
	TOKEN_DIV  shift 98
	.  reduce 97


state 172
	arith_expr : arith_expr . TOKEN_ADD arith_expr
	arith_expr : arith_expr . TOKEN_SUB arith_expr
	arith_expr : arith_expr . TOKEN_MUL arith_expr
	arith_expr : arith_expr . TOKEN_DIV arith_expr
	relative_expr : arith_expr TOKEN_LESS_EQUAL arith_expr .  (98)

	TOKEN_ADD  shift 95
	TOKEN_SUB  shift 96
	TOKEN_MUL  shift 97
	TOKEN_DIV  shift 98
	.  reduce 98


state 173
	logic_expr : logic_expr . TOKEN_AND logic_expr
	logic_expr : logic_expr TOKEN_OR logic_expr .  (102)
	logic_expr : logic_expr . TOKEN_OR logic_expr
	logic_expr : logic_expr . TOKEN_XOR logic_expr

	TOKEN_XOR  shift 127
	TOKEN_AND  shift 128
	.  reduce 102


state 174
	logic_expr : logic_expr . TOKEN_AND logic_expr
	logic_expr : logic_expr . TOKEN_OR logic_expr
	logic_expr : logic_expr TOKEN_XOR logic_expr .  (103)
	logic_expr : logic_expr . TOKEN_XOR logic_expr

	TOKEN_AND  shift 128
	.  reduce 103


state 175
	logic_expr : logic_expr TOKEN_AND logic_expr .  (101)
	logic_expr : logic_expr . TOKEN_AND logic_expr
	logic_expr : logic_expr . TOKEN_OR logic_expr
	logic_expr : logic_expr . TOKEN_XOR logic_expr

	.  reduce 101


state 176
	sentence : while_begin_keyword logic_expr sentence_list TOKEN_WHILE_END .  (19)

	.  reduce 19


state 177
	sentence : on_keyword TOKEN_BASIC_ERROR TOKEN_GOTO error .  (31)

	.  reduce 31


state 178
	sentence : on_keyword TOKEN_BASIC_ERROR TOKEN_GOTO identification .  (30)

	.  reduce 30


state 179
	sentence : on_keyword TOKEN_BASIC_ERROR TOKEN_GOSUB error .  (33)

	.  reduce 33


state 180
	sentence : on_keyword TOKEN_BASIC_ERROR TOKEN_GOSUB identification .  (32)

	.  reduce 32


state 181
	sentence : on_keyword arith_expr TOKEN_GOTO error .  (26)

	.  reduce 26


state 182
	identification_list : identification .  (113)

	.  reduce 113


state 183
	sentence : on_keyword arith_expr TOKEN_GOTO identification_list .  (25)
	identification_list : identification_list . TOKEN_COMMA identification

	TOKEN_COMMA  shift 199
	.  reduce 25


state 184
	sentence : on_keyword arith_expr TOKEN_GOSUB error .  (28)

	.  reduce 28


state 185
	sentence : on_keyword arith_expr TOKEN_GOSUB identification_list .  (27)
	identification_list : identification_list . TOKEN_COMMA identification

	TOKEN_COMMA  shift 199
	.  reduce 27


state 186
	arith_expr : arith_expr . TOKEN_ADD arith_expr
	arith_expr : arith_expr . TOKEN_SUB arith_expr
	arith_expr : arith_expr . TOKEN_MUL arith_expr
	arith_expr : arith_expr . TOKEN_DIV arith_expr
	arith_expr_list : arith_expr_list TOKEN_COMMA arith_expr .  (112)

	TOKEN_ADD  shift 95
	TOKEN_SUB  shift 96
	TOKEN_MUL  shift 97
	TOKEN_DIV  shift 98
	.  reduce 112


state 187
	sentence : function parenthese_expr modifier_list TOKEN_EQUAL arith_expr .  (13)
	arith_expr : arith_expr . TOKEN_ADD arith_expr
	arith_expr : arith_expr . TOKEN_SUB arith_expr
	arith_expr : arith_expr . TOKEN_MUL arith_expr
	arith_expr : arith_expr . TOKEN_DIV arith_expr

	TOKEN_ADD  shift 95
	TOKEN_SUB  shift 96
	TOKEN_MUL  shift 97
	TOKEN_DIV  shift 98
	.  reduce 13


state 188
	modifier_list : modifier_list modifier parenthese_expr .  (62)

	.  reduce 62


state 189
	output_format : output_item TOKEN_LEFT_SQUARE_BRACKET arith_expr error .  (54)

	.  reduce 54


state 190
	output_format : output_item TOKEN_LEFT_SQUARE_BRACKET arith_expr TOKEN_COMMA . arith_expr TOKEN_RIGHT_SQUARE_BRACKET
	output_format : output_item TOKEN_LEFT_SQUARE_BRACKET arith_expr TOKEN_COMMA . arith_expr error

	error  shift 46
	TOKEN_ON  shift 47
	TOKEN_SUB  shift 48
	TOKEN_LEFT_PARENTHESIS  shift 49
	TOKEN_IDENTIFICATION  shift 11
	TOKEN_INTEGER_FUNCTION_NAME  shift 12
	TOKEN_DOUBLE_FUNCTION_NAME  shift 13
	TOKEN_CONST_INT  shift 51
	TOKEN_CONST_DOUBLE  shift 52

	identification  goto 54
	arith_expr  goto 200
	function  goto 56


state 191
	output_format : output_item TOKEN_LEFT_SQUARE_BRACKET arith_expr TOKEN_RIGHT_SQUARE_BRACKET .  (52)

	.  reduce 52


state 192
	output_item : number_string TOKEN_LEFT_PARENTHESIS arith_expr error .  (60)

	.  reduce 60


state 193
	output_item : number_string TOKEN_LEFT_PARENTHESIS arith_expr TOKEN_RIGHT_PARENTHESIS .  (58)

	.  reduce 58


state 194
	else_sub_sentence : TOKEN_ELSEIF logic_expr error .  (79)

	.  reduce 79


state 195
	else_sub_sentence : TOKEN_ELSEIF logic_expr TOKEN_THEN .  (78)

	.  reduce 78


state 196
	else_sentence : else_sub_sentence sentence_list else_sentence .  (77)

	.  reduce 77


state 197
	for_3 : TOKEN_STEP arith_expr .  (69)
	arith_expr : arith_expr . TOKEN_ADD arith_expr
	arith_expr : arith_expr . TOKEN_SUB arith_expr
	arith_expr : arith_expr . TOKEN_MUL arith_expr
	arith_expr : arith_expr . TOKEN_DIV arith_expr

	TOKEN_ADD  shift 95
	TOKEN_SUB  shift 96
	TOKEN_MUL  shift 97
	TOKEN_DIV  shift 98
	.  reduce 69


state 198
	sentence : for_head for_1 for_2 for_3 sentence_list . for_tail

	TOKEN_NEXT  shift 201

	for_tail  goto 202


state 199
	identification_list : identification_list TOKEN_COMMA . identification

	TOKEN_IDENTIFICATION  shift 11

	identification  goto 203


state 200
	output_format : output_item TOKEN_LEFT_SQUARE_BRACKET arith_expr TOKEN_COMMA arith_expr . TOKEN_RIGHT_SQUARE_BRACKET
	output_format : output_item TOKEN_LEFT_SQUARE_BRACKET arith_expr TOKEN_COMMA arith_expr . error
	arith_expr : arith_expr . TOKEN_ADD arith_expr
	arith_expr : arith_expr . TOKEN_SUB arith_expr
	arith_expr : arith_expr . TOKEN_MUL arith_expr
	arith_expr : arith_expr . TOKEN_DIV arith_expr

	error  shift 204
	TOKEN_ADD  shift 95
	TOKEN_SUB  shift 96
	TOKEN_MUL  shift 97
	TOKEN_DIV  shift 98
	TOKEN_RIGHT_SQUARE_BRACKET  shift 205


state 201
	for_tail : TOKEN_NEXT . identification
	for_tail : TOKEN_NEXT . error

	error  shift 206
	TOKEN_IDENTIFICATION  shift 11

	identification  goto 207


state 202
	sentence : for_head for_1 for_2 for_3 sentence_list for_tail .  (17)

	.  reduce 17


state 203
	identification_list : identification_list TOKEN_COMMA identification .  (114)

	.  reduce 114


state 204
	output_format : output_item TOKEN_LEFT_SQUARE_BRACKET arith_expr TOKEN_COMMA arith_expr error .  (55)

	.  reduce 55


state 205
	output_format : output_item TOKEN_LEFT_SQUARE_BRACKET arith_expr TOKEN_COMMA arith_expr TOKEN_RIGHT_SQUARE_BRACKET .  (53)

	.  reduce 53


state 206
	for_tail : TOKEN_NEXT error .  (72)

	.  reduce 72


state 207
	for_tail : TOKEN_NEXT identification .  (71)

	.  reduce 71


##############################################################################
# Summary
##############################################################################

53 token(s), 40 nonterminal(s)
129 grammar rule(s), 208 state(s)


##############################################################################
# End of File
##############################################################################
