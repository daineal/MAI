
#include <stdio.h>
#include <wchar.h>

//Функции
void addToSet(unsigned int *s, int c)
{
	*s |= charBit(c);
}

void removeFromSet(unsigned int *s, int c)
{
	*s &= ~charBit(c);
}

void clearSet(unsigned int *s)
{
	*s = 0;
}

unsigned int setSubtract(unsigned int s, unsigned int a)
{
	return (s & ~a);
}

unsigned int setCross(unsigned int s1, unsigned int s2)
{
	return (s1 & s2);
}

int isEmptySet(unsigned int s)
{
	return (s != 0);
}

int isKeyExists(unsigned int s, int c)
{
	return ((s & charBit(c)) != 0);
}

int toLower(int c)
{
	return (c >= 1040 && c <= 1071 ? c - 1040 + 1072 : c);
}

int isSpace(int c)
{
	return (c == ' ' || c == ',' || c == '\n' || c == '\t');
}

int isLetter(int c)
{
	return (c >= 1072 && c <= 1103);
}

int charBit(int c)
{
	return (1 << (c - 1072));
}

int main(void)
{
	char letter;
	int ch, isInput = 0, num = 0, numCurrent = 0;
	unsigned int set1 = 0, set2 = 0, soglSet = 0, word = 0, letterSet = 0;
	unsigned int res = 0;

	for (int i = 0; i < 32; i++) addToSet(&letterSet, 1072 + i);

	addToSet(&set1, 1072);
	addToSet(&set1, 1086);
	addToSet(&set1, 1091);
	addToSet(&set1, 1101);
	addToSet(&set1, 1090);
	addToSet(&set1, 1080);

	addToSet(&set2, 1103);
	addToSet(&set2, 1102);
	addToSet(&set2, 1077);

	while ((ch = getwchar()) != EOF)
	{
		if (ch == 1105) ch=1077;
		//printf(" %d",ch);
		ch = toLower(ch);

		if (!isSpace(ch))
		{
			if (!isInput)
			{
				num++;
				isInput = 1;
			}

			if (isLetter(ch) && isKeyExists(set1, ch)) addToSet(&word, ch);
    	if (isLetter(ch) && isKeyExists(set2, ch)) addToSet(&word, ch);
		}
		else
		{
			if (setCross(word,set1)==0&&setCross(word,set2)>0) {numCurrent = num;}
			isInput = 0;
      clearSet(&word);
		}
	}

	if (numCurrent >0) printf("Слово #%d включает гласные второго рода и не включает гласные первого рода\n", numCurrent);
	else printf("Нет слов , включающих гласные  второго рода и не включающих гласные первого рода\n");

	return 0;
}
