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
# lexer.v
# Lex verbose file generated from lexer.l.
# 
# Date: 05/01/11
# Time: 16:41:28
# 
# ALex Version: 2.07
#############################################################################


#############################################################################
# Expressions
#############################################################################

    1  [0-9]+

    2  "$"[0-9]+

    3  ([0-9]+)\.([0-9]*)

    4  "true"

    5  "off"|"false"

    6  "pi"

    7  "("

    8  ")"

    9  "["

   10  "]"

   11  "*"

   12  "/"

   13  "+"

   14  "-"

   15  "="

   16  "<>"

   17  ">"

   18  ">="

   19  "<"

   20  "<="

   21  "not"

   22  "and"

   23  "or"

   24  "xor"

   25  ":"

   26  ";"

   27  ","

   28  "if"

   29  "then"

   30  "else"

   31  "endif"

   32  "elseif"

   33  "for"

   34  "to"

   35  "step"

   36  "next"

   37  "repeat"

   38  "until"

   39  "while"

   40  "wend"

   41  "goto"

   42  "gosub"

   43  "return"

   44  "on"

   45  "basicerror"

   46  "wait"[ \t]+"until"

   47  "wait"[ \t]+"idle"

   48  "wait"[ \t]+"loaded"

   49  "chr"

   50  "hex"

   51  "#"[0-9]+

   52  [a-zA-Z][0-9a-zA-Z]*("#"{0,1})

   53  \"[^\r\n\"]*\"

   54  [\r]

   55  "'"[^\r]*

   56  ([ \t\n])+


#############################################################################
# States
#############################################################################

state 1
	INITIAL

	0x09 - 0x0a (2)    goto 3
	0x0d               goto 4
	0x20               goto 3
	0x22               goto 5
	0x23               goto 6
	0x24               goto 7
	0x27               goto 8
	0x28               goto 9
	0x29               goto 10
	0x2a               goto 11
	0x2b               goto 12
	0x2c               goto 13
	0x2d               goto 14
	0x2f               goto 15
	0x30 - 0x39 (10)   goto 16
	0x3a               goto 17
	0x3b               goto 18
	0x3c               goto 19
	0x3d               goto 20
	0x3e               goto 21
	0x41 - 0x5a (26)   goto 22
	0x5b               goto 23
	0x5d               goto 24
	0x61               goto 25
	0x62               goto 26
	0x63               goto 27
	0x64               goto 22
	0x65               goto 28
	0x66               goto 29
	0x67               goto 30
	0x68               goto 31
	0x69               goto 32
	0x6a - 0x6d (4)    goto 22
	0x6e               goto 33
	0x6f               goto 34
	0x70               goto 35
	0x71               goto 22
	0x72               goto 36
	0x73               goto 37
	0x74               goto 38
	0x75               goto 39
	0x76               goto 22
	0x77               goto 40
	0x78               goto 41
	0x79 - 0x7a (2)    goto 22


state 2
	^INITIAL

	0x09 - 0x0a (2)    goto 3
	0x0d               goto 4
	0x20               goto 3
	0x22               goto 5
	0x23               goto 6
	0x24               goto 7
	0x27               goto 8
	0x28               goto 9
	0x29               goto 10
	0x2a               goto 11
	0x2b               goto 12
	0x2c               goto 13
	0x2d               goto 14
	0x2f               goto 15
	0x30 - 0x39 (10)   goto 16
	0x3a               goto 17
	0x3b               goto 18
	0x3c               goto 19
	0x3d               goto 20
	0x3e               goto 21
	0x41 - 0x5a (26)   goto 22
	0x5b               goto 23
	0x5d               goto 24
	0x61               goto 25
	0x62               goto 26
	0x63               goto 27
	0x64               goto 22
	0x65               goto 28
	0x66               goto 29
	0x67               goto 30
	0x68               goto 31
	0x69               goto 32
	0x6a - 0x6d (4)    goto 22
	0x6e               goto 33
	0x6f               goto 34
	0x70               goto 35
	0x71               goto 22
	0x72               goto 36
	0x73               goto 37
	0x74               goto 38
	0x75               goto 39
	0x76               goto 22
	0x77               goto 40
	0x78               goto 41
	0x79 - 0x7a (2)    goto 22


state 3
	0x09 - 0x0a (2)    goto 3
	0x20               goto 3

	match 56


state 4
	match 54


state 5
	0x00 - 0x09 (10)   goto 5
	0x0b - 0x0c (2)    goto 5
	0x0e - 0x21 (20)   goto 5
	0x22               goto 42
	0x23 - 0xff (221)  goto 5


state 6
	0x30 - 0x39 (10)   goto 43


state 7
	0x30 - 0x39 (10)   goto 44


state 8
	0x00 - 0x0c (13)   goto 8
	0x0e - 0xff (242)  goto 8

	match 55


state 9
	match 7


state 10
	match 8


state 11
	match 11


state 12
	match 13


state 13
	match 27


state 14
	match 14


state 15
	match 12


state 16
	0x2e               goto 45
	0x30 - 0x39 (10)   goto 16

	match 1


state 17
	match 25


state 18
	match 26


state 19
	0x3d               goto 46
	0x3e               goto 47

	match 19


state 20
	match 15


state 21
	0x3d               goto 48

	match 17


state 22
	0x23               goto 49
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x61 - 0x7a (26)   goto 22

	match 52


state 23
	match 9


state 24
	match 10


state 25
	0x23               goto 49
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x61 - 0x6d (13)   goto 22
	0x6e               goto 50
	0x6f - 0x7a (12)   goto 22

	match 52


state 26
	0x23               goto 49
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x61               goto 51
	0x62 - 0x7a (25)   goto 22

	match 52


state 27
	0x23               goto 49
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x61 - 0x67 (7)    goto 22
	0x68               goto 52
	0x69 - 0x7a (18)   goto 22

	match 52


state 28
	0x23               goto 49
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x61 - 0x6b (11)   goto 22
	0x6c               goto 53
	0x6d               goto 22
	0x6e               goto 54
	0x6f - 0x7a (12)   goto 22

	match 52


state 29
	0x23               goto 49
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x61               goto 55
	0x62 - 0x6e (13)   goto 22
	0x6f               goto 56
	0x70 - 0x7a (11)   goto 22

	match 52


state 30
	0x23               goto 49
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x61 - 0x6e (14)   goto 22
	0x6f               goto 57
	0x70 - 0x7a (11)   goto 22

	match 52


state 31
	0x23               goto 49
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x61 - 0x64 (4)    goto 22
	0x65               goto 58
	0x66 - 0x7a (21)   goto 22

	match 52


state 32
	0x23               goto 49
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x61 - 0x65 (5)    goto 22
	0x66               goto 59
	0x67 - 0x7a (20)   goto 22

	match 52


state 33
	0x23               goto 49
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x61 - 0x64 (4)    goto 22
	0x65               goto 60
	0x66 - 0x6e (9)    goto 22
	0x6f               goto 61
	0x70 - 0x7a (11)   goto 22

	match 52


state 34
	0x23               goto 49
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x61 - 0x65 (5)    goto 22
	0x66               goto 62
	0x67 - 0x6d (7)    goto 22
	0x6e               goto 63
	0x6f - 0x71 (3)    goto 22
	0x72               goto 64
	0x73 - 0x7a (8)    goto 22

	match 52


state 35
	0x23               goto 49
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x61 - 0x68 (8)    goto 22
	0x69               goto 65
	0x6a - 0x7a (17)   goto 22

	match 52


state 36
	0x23               goto 49
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x61 - 0x64 (4)    goto 22
	0x65               goto 66
	0x66 - 0x7a (21)   goto 22

	match 52


state 37
	0x23               goto 49
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x61 - 0x73 (19)   goto 22
	0x74               goto 67
	0x75 - 0x7a (6)    goto 22

	match 52


state 38
	0x23               goto 49
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x61 - 0x67 (7)    goto 22
	0x68               goto 68
	0x69 - 0x6e (6)    goto 22
	0x6f               goto 69
	0x70 - 0x71 (2)    goto 22
	0x72               goto 70
	0x73 - 0x7a (8)    goto 22

	match 52


state 39
	0x23               goto 49
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x61 - 0x6d (13)   goto 22
	0x6e               goto 71
	0x6f - 0x7a (12)   goto 22

	match 52


state 40
	0x23               goto 49
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x61               goto 72
	0x62 - 0x64 (3)    goto 22
	0x65               goto 73
	0x66 - 0x67 (2)    goto 22
	0x68               goto 74
	0x69 - 0x7a (18)   goto 22

	match 52


state 41
	0x23               goto 49
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x61 - 0x6e (14)   goto 22
	0x6f               goto 75
	0x70 - 0x7a (11)   goto 22

	match 52


state 42
	match 53


state 43
	0x30 - 0x39 (10)   goto 43

	match 51


state 44
	0x30 - 0x39 (10)   goto 44

	match 2


state 45
	0x30 - 0x39 (10)   goto 45

	match 3


state 46
	match 20


state 47
	match 16


state 48
	match 18


state 49
	match 52


state 50
	0x23               goto 49
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x61 - 0x63 (3)    goto 22
	0x64               goto 76
	0x65 - 0x7a (22)   goto 22

	match 52


state 51
	0x23               goto 49
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x61 - 0x72 (18)   goto 22
	0x73               goto 77
	0x74 - 0x7a (7)    goto 22

	match 52


state 52
	0x23               goto 49
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x61 - 0x71 (17)   goto 22
	0x72               goto 78
	0x73 - 0x7a (8)    goto 22

	match 52


state 53
	0x23               goto 49
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x61 - 0x72 (18)   goto 22
	0x73               goto 79
	0x74 - 0x7a (7)    goto 22

	match 52


state 54
	0x23               goto 49
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x61 - 0x63 (3)    goto 22
	0x64               goto 80
	0x65 - 0x7a (22)   goto 22

	match 52


state 55
	0x23               goto 49
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x61 - 0x6b (11)   goto 22
	0x6c               goto 81
	0x6d - 0x7a (14)   goto 22

	match 52


state 56
	0x23               goto 49
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x61 - 0x71 (17)   goto 22
	0x72               goto 82
	0x73 - 0x7a (8)    goto 22

	match 52


state 57
	0x23               goto 49
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x61 - 0x72 (18)   goto 22
	0x73               goto 83
	0x74               goto 84
	0x75 - 0x7a (6)    goto 22

	match 52


state 58
	0x23               goto 49
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x61 - 0x77 (23)   goto 22
	0x78               goto 85
	0x79 - 0x7a (2)    goto 22

	match 52


state 59
	0x23               goto 49
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x61 - 0x7a (26)   goto 22

	match 28


state 60
	0x23               goto 49
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x61 - 0x77 (23)   goto 22
	0x78               goto 86
	0x79 - 0x7a (2)    goto 22

	match 52


state 61
	0x23               goto 49
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x61 - 0x73 (19)   goto 22
	0x74               goto 87
	0x75 - 0x7a (6)    goto 22

	match 52


state 62
	0x23               goto 49
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x61 - 0x65 (5)    goto 22
	0x66               goto 88
	0x67 - 0x7a (20)   goto 22

	match 52


state 63
	0x23               goto 49
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x61 - 0x7a (26)   goto 22

	match 44


state 64
	0x23               goto 49
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x61 - 0x7a (26)   goto 22

	match 23


state 65
	0x23               goto 49
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x61 - 0x7a (26)   goto 22

	match 6


state 66
	0x23               goto 49
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x61 - 0x6f (15)   goto 22
	0x70               goto 89
	0x71 - 0x73 (3)    goto 22
	0x74               goto 90
	0x75 - 0x7a (6)    goto 22

	match 52


state 67
	0x23               goto 49
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x61 - 0x64 (4)    goto 22
	0x65               goto 91
	0x66 - 0x7a (21)   goto 22

	match 52


state 68
	0x23               goto 49
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x61 - 0x64 (4)    goto 22
	0x65               goto 92
	0x66 - 0x7a (21)   goto 22

	match 52


state 69
	0x23               goto 49
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x61 - 0x7a (26)   goto 22

	match 34


state 70
	0x23               goto 49
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x61 - 0x74 (20)   goto 22
	0x75               goto 93
	0x76 - 0x7a (5)    goto 22

	match 52


state 71
	0x23               goto 49
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x61 - 0x73 (19)   goto 22
	0x74               goto 94
	0x75 - 0x7a (6)    goto 22

	match 52


state 72
	0x23               goto 49
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x61 - 0x68 (8)    goto 22
	0x69               goto 95
	0x6a - 0x7a (17)   goto 22

	match 52


state 73
	0x23               goto 49
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x61 - 0x6d (13)   goto 22
	0x6e               goto 96
	0x6f - 0x7a (12)   goto 22

	match 52


state 74
	0x23               goto 49
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x61 - 0x68 (8)    goto 22
	0x69               goto 97
	0x6a - 0x7a (17)   goto 22

	match 52


state 75
	0x23               goto 49
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x61 - 0x71 (17)   goto 22
	0x72               goto 98
	0x73 - 0x7a (8)    goto 22

	match 52


state 76
	0x23               goto 49
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x61 - 0x7a (26)   goto 22

	match 22


state 77
	0x23               goto 49
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x61 - 0x68 (8)    goto 22
	0x69               goto 99
	0x6a - 0x7a (17)   goto 22

	match 52


state 78
	0x23               goto 49
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x61 - 0x7a (26)   goto 22

	match 49


state 79
	0x23               goto 49
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x61 - 0x64 (4)    goto 22
	0x65               goto 100
	0x66 - 0x7a (21)   goto 22

	match 52


state 80
	0x23               goto 49
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x61 - 0x68 (8)    goto 22
	0x69               goto 101
	0x6a - 0x7a (17)   goto 22

	match 52


state 81
	0x23               goto 49
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x61 - 0x72 (18)   goto 22
	0x73               goto 102
	0x74 - 0x7a (7)    goto 22

	match 52


state 82
	0x23               goto 49
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x61 - 0x7a (26)   goto 22

	match 33


state 83
	0x23               goto 49
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x61 - 0x74 (20)   goto 22
	0x75               goto 103
	0x76 - 0x7a (5)    goto 22

	match 52


state 84
	0x23               goto 49
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x61 - 0x6e (14)   goto 22
	0x6f               goto 104
	0x70 - 0x7a (11)   goto 22

	match 52


state 85
	0x23               goto 49
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x61 - 0x7a (26)   goto 22

	match 50


state 86
	0x23               goto 49
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x61 - 0x73 (19)   goto 22
	0x74               goto 105
	0x75 - 0x7a (6)    goto 22

	match 52


state 87
	0x23               goto 49
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x61 - 0x7a (26)   goto 22

	match 21


state 88
	0x23               goto 49
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x61 - 0x7a (26)   goto 22

	match 5


state 89
	0x23               goto 49
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x61 - 0x64 (4)    goto 22
	0x65               goto 106
	0x66 - 0x7a (21)   goto 22

	match 52


state 90
	0x23               goto 49
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x61 - 0x74 (20)   goto 22
	0x75               goto 107
	0x76 - 0x7a (5)    goto 22

	match 52


state 91
	0x23               goto 49
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x61 - 0x6f (15)   goto 22
	0x70               goto 108
	0x71 - 0x7a (10)   goto 22

	match 52


state 92
	0x23               goto 49
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x61 - 0x6d (13)   goto 22
	0x6e               goto 109
	0x6f - 0x7a (12)   goto 22

	match 52


state 93
	0x23               goto 49
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x61 - 0x64 (4)    goto 22
	0x65               goto 110
	0x66 - 0x7a (21)   goto 22

	match 52


state 94
	0x23               goto 49
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x61 - 0x68 (8)    goto 22
	0x69               goto 111
	0x6a - 0x7a (17)   goto 22

	match 52


state 95
	0x23               goto 49
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x61 - 0x73 (19)   goto 22
	0x74               goto 112
	0x75 - 0x7a (6)    goto 22

	match 52


state 96
	0x23               goto 49
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x61 - 0x63 (3)    goto 22
	0x64               goto 113
	0x65 - 0x7a (22)   goto 22

	match 52


state 97
	0x23               goto 49
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x61 - 0x6b (11)   goto 22
	0x6c               goto 114
	0x6d - 0x7a (14)   goto 22

	match 52


state 98
	0x23               goto 49
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x61 - 0x7a (26)   goto 22

	match 24


state 99
	0x23               goto 49
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x61 - 0x62 (2)    goto 22
	0x63               goto 115
	0x64 - 0x7a (23)   goto 22

	match 52


state 100
	0x23               goto 49
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x61 - 0x68 (8)    goto 22
	0x69               goto 116
	0x6a - 0x7a (17)   goto 22

	match 30


state 101
	0x23               goto 49
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x61 - 0x65 (5)    goto 22
	0x66               goto 117
	0x67 - 0x7a (20)   goto 22

	match 52


state 102
	0x23               goto 49
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x61 - 0x64 (4)    goto 22
	0x65               goto 88
	0x66 - 0x7a (21)   goto 22

	match 52


state 103
	0x23               goto 49
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x61               goto 22
	0x62               goto 118
	0x63 - 0x7a (24)   goto 22

	match 52


state 104
	0x23               goto 49
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x61 - 0x7a (26)   goto 22

	match 41


state 105
	0x23               goto 49
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x61 - 0x7a (26)   goto 22

	match 36


state 106
	0x23               goto 49
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x61               goto 119
	0x62 - 0x7a (25)   goto 22

	match 52


state 107
	0x23               goto 49
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x61 - 0x71 (17)   goto 22
	0x72               goto 120
	0x73 - 0x7a (8)    goto 22

	match 52


state 108
	0x23               goto 49
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x61 - 0x7a (26)   goto 22

	match 35


state 109
	0x23               goto 49
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x61 - 0x7a (26)   goto 22

	match 29


state 110
	0x23               goto 49
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x61 - 0x7a (26)   goto 22

	match 4


state 111
	0x23               goto 49
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x61 - 0x6b (11)   goto 22
	0x6c               goto 121
	0x6d - 0x7a (14)   goto 22

	match 52


state 112
	0x09               goto 122
	0x20               goto 122
	0x23               goto 49
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x61 - 0x7a (26)   goto 22

	match 52


state 113
	0x23               goto 49
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x61 - 0x7a (26)   goto 22

	match 40


state 114
	0x23               goto 49
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x61 - 0x64 (4)    goto 22
	0x65               goto 123
	0x66 - 0x7a (21)   goto 22

	match 52


state 115
	0x23               goto 49
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x61 - 0x64 (4)    goto 22
	0x65               goto 124
	0x66 - 0x7a (21)   goto 22

	match 52


state 116
	0x23               goto 49
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x61 - 0x65 (5)    goto 22
	0x66               goto 125
	0x67 - 0x7a (20)   goto 22

	match 52


state 117
	0x23               goto 49
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x61 - 0x7a (26)   goto 22

	match 31


state 118
	0x23               goto 49
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x61 - 0x7a (26)   goto 22

	match 42


state 119
	0x23               goto 49
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x61 - 0x73 (19)   goto 22
	0x74               goto 126
	0x75 - 0x7a (6)    goto 22

	match 52


state 120
	0x23               goto 49
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x61 - 0x6d (13)   goto 22
	0x6e               goto 127
	0x6f - 0x7a (12)   goto 22

	match 52


state 121
	0x23               goto 49
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x61 - 0x7a (26)   goto 22

	match 38


state 122
	0x09               goto 122
	0x20               goto 122
	0x69               goto 128
	0x6c               goto 129
	0x75               goto 130


state 123
	0x23               goto 49
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x61 - 0x7a (26)   goto 22

	match 39


state 124
	0x23               goto 49
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x61 - 0x71 (17)   goto 22
	0x72               goto 131
	0x73 - 0x7a (8)    goto 22

	match 52


state 125
	0x23               goto 49
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x61 - 0x7a (26)   goto 22

	match 32


state 126
	0x23               goto 49
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x61 - 0x7a (26)   goto 22

	match 37


state 127
	0x23               goto 49
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x61 - 0x7a (26)   goto 22

	match 43


state 128
	0x64               goto 132


state 129
	0x6f               goto 133


state 130
	0x6e               goto 134


state 131
	0x23               goto 49
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x61 - 0x71 (17)   goto 22
	0x72               goto 135
	0x73 - 0x7a (8)    goto 22

	match 52


state 132
	0x6c               goto 136


state 133
	0x61               goto 137


state 134
	0x74               goto 138


state 135
	0x23               goto 49
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x61 - 0x6e (14)   goto 22
	0x6f               goto 139
	0x70 - 0x7a (11)   goto 22

	match 52


state 136
	0x65               goto 140


state 137
	0x64               goto 141


state 138
	0x69               goto 142


state 139
	0x23               goto 49
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x61 - 0x71 (17)   goto 22
	0x72               goto 143
	0x73 - 0x7a (8)    goto 22

	match 52


state 140
	match 47


state 141
	0x65               goto 144


state 142
	0x6c               goto 145


state 143
	0x23               goto 49
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x61 - 0x7a (26)   goto 22

	match 45


state 144
	0x64               goto 146


state 145
	match 46


state 146
	match 48


#############################################################################
# Summary
#############################################################################

1 start state(s)
56 expression(s), 146 state(s)


#############################################################################
# End of File
#############################################################################
