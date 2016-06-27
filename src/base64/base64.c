#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_LEN 100

static char base64digits[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ\
abcdefghijklmnopqrstuvwxyz\
0123456789+/=";

/*
 * get the length of str exclude '\0'
 */
int
get_len_str(char *str) {
	int len = 0;

	if(str == NULL)
		return len;
	while(*str != '\0') {
		str++;
		len++;
	}

	return len;
}

/*
 * the encode method of base64
 */

char *
encode(char *str) {
	int	len = get_len_str(str);
	char	*binary_str = malloc(8*len*sizeof(char));
	char	*temp = str;
	char	*cur;
	int	len_part = 0, len_remain = 0, len_bina = len * 8;
	int	index = 0;

	for (int m=0; m<len; m++) {
		for (int n=8; n>=1; n--) {
			if (*temp & 0x80)
				strcat(binary_str, "1");
			else
				strcat(binary_str, "0");
			*temp = *temp << 1;
		}
		temp++;
	}
	len_remain = len_bina%6;
	len_part = ((len_bina%6) == 0) ? (len_bina/6) : (len_bina/6+1);
	char	*end_str = malloc((len_part+(6-len_remain)/2)*sizeof(char));
	cur = binary_str;
	for (int i=0; i<len_part; i++) {
		index = 0;
		if ((i==(len_part-1)) && len_remain!=0) {
			for (int k=0; k<len_remain; k++) {
				index = index << 1;
				if (*cur == '1')
					index = index | 0x1;
				cur++;
			}
			index = index << (6-len_remain);
		}
		for (int j=1; j<=6; j++) {
			index = index << 1;
			if(*cur == '1')
				index = index | 0x1;
				cur++;
		}
		strncat(end_str, base64digits+index, 1);	
	}
	/*switch(6-len_remain) {
		case 2:
			strcat(end_str, "=");
			break;
		case 4:
			strcat(end_str, "==");
			break;
		default:
			break;
	}*/
	free(binary_str);

	return end_str;
}

/*
 * get char's location index in array base64digits 
 */
int
get_index(char *str, char c) {
	int	index = 0;

	while(*str != c) {
		index++;
		str++;
	}

	return index;
}

/*
 * the decode method of base64
 */
char *
decode(char *str) {
	int	len = get_len_str(str);
	char	*binary_str = malloc((6*len+1)*sizeof(char));
	char	*char_str = malloc(((len*6)/8)*sizeof(char));
	int	index = 0, temp = 0;
	char	*cur = binary_str;
	char	*swap;
	char	a;

	memset(binary_str, '\0', sizeof(binary_str)-1);
	memset(char_str, '\0', sizeof(char_str)-1);
	for (int i=0; i<len; i++) {
		index = get_index(base64digits, *(str+i));
		index = index << 2; 
		for(int n=6; n>=1; n--) {
			if (index & 0x80)
				strcat(binary_str, "1");
			else
				strcat(binary_str, "0");
			index = index << 1;
		}
	}
	for (int j=0; j<((len*6)/8); j++) {
		temp = 0;
		for (int m=1; m<=8; m++) {
			temp = temp << 1;
			if (*cur == '1')
				temp = temp | 0x1;
			cur++;
		}
		a = toascii(temp);
		swap = &a;
		strncat(char_str, swap, 1);
	}
	free(binary_str);

	return char_str;
}

int
main(void) {
	int	len=0;
	char	*en_result = malloc(MAX_LEN*sizeof(char));
	char	*de_result;
	
	char src_str[MAX_LEN] = "abcd";
	printf("测试字符串:%s\n", src_str);
	en_result = encode(src_str);
	printf("the result of encode:");
	printf("%s\n", en_result);
	de_result = decode(en_result);
	printf("the result of decode:");
	printf("%s\n", de_result);

	return 0;
}
