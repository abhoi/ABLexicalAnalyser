/*  CREATED ON AUG 01 2015
	AMLAAN BHOI
	https://in.linkedin.com/in/amlaanb
	https://github.com/amlaanb
	https://twitter.com/amlaanb
									*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

char *key[]={"void","main","char","float"};

void append(char* s, char c) {
        int len = strlen(s);
        s[len] = c;
        s[len+1] = '\0';
}

int lexAnalysis(char *str, int len) {
	int i = 0, j;
	char curr, next;
	char t[100] = "";
	char tw[100] = "";
	char tl[100] = "";
	loop: 
	if (i == len) {
		return 0;
	}
	curr = str[i];
	switch (curr) {
		// ab_stringLiterals
		case '"':
			i++;
			do {
				curr = str[i];
				append(tl, curr);
				i++;
			} while (curr != '"');
			tl[strlen(tl) - 1] = 0;
			printf("<%s, literal>\n", tl);
			memset(tl, 0, 100);
			goto loop;
			break;

		// ab_digits
		case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8':  case '9':
			if (strlen(tw) > 0) {
				printf("<%s, identifier>\n", tw);
				memset(tw, 0, 100);
			}
			append(t, curr);
			i++;
			goto loop;
			break;

		// ab_keywordsAndIdentifiers
		case 'a': case 'b': case 'c': case 'd': case 'e': case 'f': case 'g': case 'h': case 'i': case 'j': case 'k': case 'l': case 'm': case 'n': case 'o': case 'p': case 'q': case 'r': case 's': case 't': case 'u': case 'v': case 'w': case 'x': case 'y': case 'z': case 'A': case 'B': case 'C': case 'D': case 'E': case 'F': case 'G': case 'H': case 'I': case 'J': case 'K': case 'L': case 'M': case 'N': case 'O': case 'P': case 'Q': case 'R': case 'S': case 'T': case 'U': case 'V': case 'W': case 'X': case 'Y': case 'Z':
			if (strlen(t) > 0) {
				printf("<%s, digit>\n", t);
				memset(t, 0, 100);
			}
			// if and int
			if (curr == 'i') {
				i++;
				next = str[i];
				if (next == 'f') {
					if (strlen(tw) > 0) {
						printf("<%s, identifier>\n", tw);
						memset(tw, 0, 100);
					}
					printf("<if, keyword>\n");
					i++;
					goto loop;
				} else if (next == 'n') {
					i++;
					next = str[i];
					if (next == 't') {
						if (strlen(tw) > 0) {
							printf("<%s, identifier>\n", tw);
							memset(tw, 0, 100);
						}
						printf("<int, keyword>\n");
						i++;
						goto loop;
					} else {
						i -= 2;
					}
				} else {
					i--;
				}
			}

			// else and else if
			if (curr == 'e') {
				i++;
				next = str[i];
				if (next == 'l') {
					i++;
					next = str[i];
					if (next == 's') {
						i++;
						next = str[i];
						if (next == 'e') {
							i++;
							next = str[i];
							if (next == ' ') {
								i++;
								next = str[i];
								if (next == 'i') {
									i++;
									next = str[i];
									if (next == 'f') {
										if (strlen(tw) > 0) {
											printf("<%s, identifier>\n", tw);
											memset(tw, 0, 100);
										}
										printf("<else if, keyword>\n");
										i++;
										goto loop;
									} else {
										i -= 6;
									}
								} else {
									i -= 5;
								}
							} else {
								i -= 4;
							}
						} else {
							i -= 3;
						}
					} else {
						i -= 2;
					}
				} else {
					i--;
				}
			}

			// main
			if (curr == 'm') {
				i++;
				next = str[i];
				if (next == 'a') {
					i++;
					next = str[i];
					if (next == 'i') {
						i++;
						next = str[i];
						if (next == 'n') {
							if (strlen(tw) > 0) {
								printf("<%s, identifier>\n", tw);
								memset(tw, 0, 100);
							}
							printf("<main, keyword>\n");
						i++;
						goto loop;
						} else {
							i -= 3;
						}
					} else {
						i -= 2;
					}
				} else {
					i--;
				}
			}

			// long
			if (curr == 'l') {
				i++;
				next = str[i];
				if (next == 'o') {
					i++;
					next = str[i];
					if (next == 'n') {
						i++;
						next = str[i];
						if (next == 'g') {
							if (strlen(tw) > 0) {
								printf("<%s, identifier>\n", tw);
								memset(tw, 0, 100);
							}
							printf("<main, keyword>\n");
						i++;
						goto loop;
						} else {
							i -= 3;
						}
					} else {
						i -= 2;
					}
				} else {
					i--;
				}
			}

			// void
			if (curr == 'v') {
				i++;
				next = str[i];
				if (next == 'o') {
					i++;
					next = str[i];
					if (next == 'i') {
						i++;
						next = str[i];
						if (next == 'd') {
							if (strlen(tw) > 0) {
								printf("<%s, identifier>\n", tw);
								memset(tw, 0, 100);
							}
							printf("<void, keyword>\n");
						i++;
						goto loop;
						} else {
							i -= 3;
						}
					} else {
						i -= 2;
					}
				} else {
					i--;
				}
			}

			// char
			if (curr == 'c') {
				i++;
				next = str[i];
				if (next == 'h') {
					i++;
					next = str[i];
					if (next == 'a') {
						i++;
						next = str[i];
						if (next == 'r') {
							if (strlen(tw) > 0) {
								printf("<%s, identifier>\n", tw);
								memset(tw, 0, 100);
							}
							printf("<char, keyword>\n");
						i++;
						goto loop;
						} else {
							i -= 3;
						}
					} else {
						i -= 2;
					}
				} else {
					i--;
				}
			}

			// while
			if (curr == 'w') {
				i++;
				next = str[i];
				if (next == 'h') {
					i++;
					next = str[i];
					if (next == 'i') {
						i++;
						next = str[i];
						if (next == 'l') {
							i++;
							next = str[i];
							if (next == 'e') {
							if (strlen(tw) > 0) {
								printf("<%s, identifier>\n", tw);
								memset(tw, 0, 100);
							}
							printf("<while, keyword>\n");
							i++;
							goto loop;
							} else {
								i -= 4;
							}
						} else {
							i -= 3;
						}
					} else {
						i -= 2;
					}
				} else {
					i--;
				}
			}

			// float
			if (curr == 'f') {
				i++;
				next = str[i];
				if (next == 'l') {
					i++;
					next = str[i];
					if (next == 'o') {
						i++;
						next = str[i];
						if (next == 'a') {
							i++;
							next = str[i];
							if (next == 't') {
							if (strlen(tw) > 0) {
								printf("<%s, identifier>\n", tw);
								memset(tw, 0, 100);
							}
							printf("<float, keyword>\n");
							i++;
							goto loop;
							} else {
								i -= 4;
							}
						} else {
							i -= 3;
						}
					} else {
						i -= 2;
					}
				} else {
					i--;
				}
			}

			// const
			if (curr == 'c') {
				i++;
				next = str[i];
				if (next == 'o') {
					i++;
					next = str[i];
					if (next == 'n') {
						i++;
						next = str[i];
						if (next == 's') {
							i++;
							next = str[i];
							if (next == 't') {
							if (strlen(tw) > 0) {
								printf("<%s, identifier>\n", tw);
								memset(tw, 0, 100);
							}
							printf("<float, keyword>\n");
							i++;
							goto loop;
							} else {
								i -= 4;
							}
						} else {
							i -= 3;
						}
					} else {
						i -= 2;
					}
				} else {
					i--;
				}
			}

			// short
			if (curr == 's') {
				i++;
				next = str[i];
				if (next == 'h') {
					i++;
					next = str[i];
					if (next == 'o') {
						i++;
						next = str[i];
						if (next == 'r') {
							i++;
							next = str[i];
							if (next == 't') {
							if (strlen(tw) > 0) {
								printf("<%s, identifier>\n", tw);
								memset(tw, 0, 100);
							}
							printf("<float, keyword>\n");
							i++;
							goto loop;
							} else {
								i -= 4;
							}
						} else {
							i -= 3;
						}
					} else {
						i -= 2;
					}
				} else {
					i--;
				}
			}

			// struct
			if (curr == 's') {
				i++;
				next = str[i];
				if (next == 't') {
					i++;
					next = str[i];
					if (next == 'r') {
						i++;
						next = str[i];
						if (next == 'u') {
							i++;
							next = str[i];
							if (next == 'c') {
								i++;
								next = str[i];
								if (next == 't') {
									if (strlen(tw) > 0) {
										printf("<%s, identifier>\n", tw);
										memset(tw, 0, 100);
									}
									printf("<struct, keyword>\n");
									i++;
									goto loop;
								} else {
									i -= 5;
								}
							} else {
								i -= 4;
							}
						} else {
							i -= 3;
						}
					} else {
						i -= 2;
					}
				} else {
					i--;
				}
			}

			append(tw, curr);
			i++;
			goto loop;
			break;

		// ab_addIncrementAssign
		case '+':
			if (strlen(tw) > 0) {
				printf("<%s, identifier>\n", tw);
				memset(tw, 0, 100);
			}
			if (strlen(t) > 0) {
				printf("<%s, digit>\n", t);
				memset(t, 0, 100);
			}
			i++;
			next = str[i];
			switch (next) {
				case '+':
					printf("<++, operator>\n");
					i++;
					break;
				case '=':
					printf("<+=, assignment>\n");
					i++;
					break;
				default:
					printf("<+, operator>\n");
			}
			goto loop;
			break;

		// ab_subtractDecrementAssign
		case '-':
			if (strlen(tw) > 0) {
				printf("<%s, identifier>\n", tw);
				memset(tw, 0, 100);
			}
			if (strlen(t) > 0) {
				printf("<%s, digit>\n", t);
				memset(t, 0, 100);
			}
			i++;
			next = str[i];
			switch (next) {
				case '-':
					printf("<--, operator>\n");
					i++;
					break;
				case '=':
					printf("<-=, assignment>\n");
					i++;
					break;
				case '>':
					printf("<->, pointer>\n");
					i++;
					break;
				default:
					printf("<-, operator>\n");
			}
			goto loop;
			break;

		// multiplyAssign
		case '*':
			if (strlen(tw) > 0) {
				printf("<%s, identifier>\n", tw);
				memset(tw, 0, 100);
			}
			if (strlen(t) > 0) {
				printf("<%s, digit>\n", t);
				memset(t, 0, 100);
			}
			i++;
			next = str[i];
			switch (next) {
				case '=':
					printf("<*=, assignment>\n");
					i++;
					break;
				default:
					printf("<*, operator>\n");
			}
			goto loop;
			break;

		// ab_divideAssign
		case '/':
			if (strlen(tw) > 0) {
				printf("<%s, identifier>\n", tw);
				memset(tw, 0, 100);
			}
			if (strlen(t) > 0) {
				printf("<%s, digit>\n", t);
				memset(t, 0, 100);
			}
			i++;
			next = str[i];
			switch (next) {
				case '=':
					printf("</=, assignment>\n");
					i++;
					break;
				default:
					printf("</, operator>\n");
			}
			goto loop;
			break;

		// ab_assignCompare
		case '=':
			if (strlen(tw) > 0) {
				printf("<%s, identifier>\n", tw);
				memset(tw, 0, 100);
			}
			if (strlen(t) > 0) {
				printf("<%s, digit>\n", t);
				memset(t, 0, 100);
			}
			i++;
			next = str[i];
			switch (next) {
				case '=':
					printf("<==, comparison>\n");
					i++;
					break;
				default:
					printf("<=, assignment>\n");
			}
			goto loop;
			break;

		// ab_modAssign
		case '%':
			if (strlen(tw) > 0) {
				printf("<%s, identifier>\n", tw);
				memset(tw, 0, 100);
			}
			if (strlen(t) > 0) {
				printf("<%s, digit>\n", t);
				memset(t, 0, 100);
			}
			i++;
			next = str[i];
			switch (next) {
				case '=':
					printf("<%%=, assignment>\n");
					i++;
					break;
				default:
					printf("<%%, operator>\n");
			}
			goto loop;
			break;

		// logicalRelation
		case '!':
			if (strlen(tw) > 0) {
				printf("<%s, identifier>\n", tw);
				memset(tw, 0, 100);
			}
			if (strlen(t) > 0) {
				printf("<%s, digit>\n", t);
				memset(t, 0, 100);
			}
			i++;
			next = str[i];
			switch (next) {
				case '=':
					printf("<!=, relational>\n");
					i++;
					break;
				default:
					printf("<!, logical>\n");
			}
			goto loop;
			break;

		// ab_whitespaces
		case ' ':
			if (strlen(tw) > 0) {
				printf("<%s, identifier>\n", tw);
				memset(tw, 0, 100);
			}
			if (strlen(t) > 0) {
				printf("<%s, digit>\n", t);
				memset(t, 0, 100);
			}
			i++;
			goto loop;

		// ab_delimiters
		case '{': case '}': case '(': case ')': case '[': case ']': case ',': case ';':
			if (strlen(tw) > 0) {
				printf("<%s, identifier>\n", tw);
				memset(tw, 0, 100);
			}
			if (strlen(t) > 0) {
				printf("<%s, digit>\n", t);
				memset(t, 0, 100);
			}
			printf("<%c, delimiter>\n", curr);
			i++;
			goto loop;
			break;

		// ab_lesserCompare
		case '<':
			if (strlen(tw) > 0) {
				printf("<%s, identifier>\n", tw);
				memset(tw, 0, 100);
			}
			if (strlen(t) > 0) {
				printf("<%s, digit>\n", t);
				memset(t, 0, 100);
			}
			i++;
			next = str[i];
			switch (next) {
				case '=':
					printf("<<=, relational>\n");
					i++;
					break;
				default:
					printf("<<, relational>\n");
			}
			goto loop;
			break;

		// ab_greaterCompare
		case '>':
			if (strlen(tw) > 0) {
				printf("<%s, identifier>\n", tw);
				memset(tw, 0, 100);
			}
			if (strlen(t) > 0) {
				printf("<%s, digit>\n", t);
				memset(t, 0, 100);
			}
			i++;
			next = str[i];
			switch (next) {
				case '=':
					printf("<>=, relational>\n");
					i++;
					break;
				default:
					printf("<>, relational>\n");
			}
			goto loop;
			break;

		default:
			if (strlen(tw) > 0) {
				printf("<%s, identifier>\n", tw);
				memset(tw, 0, 100);
			}
			if (strlen(t) > 0) {
				printf("<%s, digit>\n", t);
				memset(t, 0, 100);
			}
			i++;
			goto loop;
	}
}

/* 	DESIGNED FOR COMPILER CONSTRUCTION LAB CSE 304 */

int main() {
	char str[100], ch;
	int i = 0;
	printf("Enter string: ");
	while (ch != '\n') {
		ch = getchar();
		str[i] = ch;
		i++;
	}
	lexAnalysis(str, i);
}