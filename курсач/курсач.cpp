#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>
#include<locale.h>
#include<stdlib.h>
#include<errno.h>
#include<math.h>

//функция формирования тройки в виде слова
char* print_chislo(int chislo, int order, char* result);
//функция формирования разряда в виде слова
char* print_velichina(int chislo, int order, char* result);

char* main()//посмотреть strtal
{
	unsigned long long int value,j,nothing;
	char chislo[512];//число, которое ввели с консоли
	char *endofenter;
	int numberofdigits=0;//число цифр в числе
	int triad;//число триад(троек цифр)
	char result[1024];//итог, сформированное числительное
	char buf[1024] = { 0 };//резуьтат работы функций создания числительного
	int i;//счетчики

	system("color F0");
	setlocale(0, "rus");

	printf("Введите число:");
	scanf("%s", &chislo);
	if (isdigit(chislo[0])!=0)
		value = strtoull(chislo, &endofenter, 10);
	else
	{
		printf("Невозможное значение!!!\n");
		return;
	}
	if (errno == ERANGE)
	{
		printf("Невозможное значение!!!\n");
		return;
	}

	if (value == 0)
	{
		strcat(buf, "ноль");
		//printf("<%s>", buf);
		return buf;
	}
	else
	{
		nothing = value;
		while (nothing != 0)
		{
			nothing = nothing / 10;
			numberofdigits++;
		}
	}

	triad = numberofdigits / 3;//считаем число триад

	if (numberofdigits > (triad * 3))//проверка числа триад
		triad++;

	//производим формирование слова
	for ( i = triad;i >0; i--)
	{
		j = pow(10, (i - 1) * 3);
		if (j == ERANGE)
		{
			printf("Невозможно преобразовать данное число!!!\n");
			return '\0';
		}
		nothing = value / j;
		value = value % j;
		*buf =print_chislo(nothing, i-1, buf);//формируем тройку
		*buf =print_velichina(nothing, i - 1, buf);//формируем разряд
	}
	//затирания пробела в начале слова и получения итогового слова
	memcpy(result, buf + 1, strlen(buf) - 1);
	result[strlen(buf)-1] = '\0';
	printf("<%s>\n", result);
	return result;
}

char* print_chislo(int chislo,int order,char* result)//печать числа из соот-ей тройки чисел
{
	int i ;//номер числа в данной тройке чисел
	int first, second, third;
	first = chislo / 100;
	second = chislo / 10 - first * 10;
	third = chislo % 10;

	switch (first)
	{
		case 1:
		{
			strcat(result, " сто");
			break;
		}
		case 2:
		{
			strcat(result, " двести");
			break;
		}
		case 3:
		{
			strcat(result, " триста");
			break;
		}
		case 4:
		{
			strcat(result, " четыреста");
			break;
		}
		case 5:
		{
			strcat(result, " пятьсот");
			break;
		}
		case 6:
		{
			strcat(result, " шестьсот");
			break;
		}
		case 7:
		{
			strcat(result, " семьсот");
			break;
		}
		case 8:
		{
			strcat(result, " восемьсот");
			break;
		}
		case 9:
		{
			strcat(result, " девятьсот");
			break;
		}
		default:
			break;
	}

	if (second !=1)//десятки без чисел 11-19
	{
		switch (second)
		{
			case 2:
			{
				strcat(result, " двадцать");
				break;
			}
			case 3:
			{
				strcat(result, " тридцать");
				break;
			}
			case 4:
			{
				strcat(result, " сорок");
				break;
			}
			case 5:
			{
				strcat(result, " пятьдесят");
				break;
			}
			case 6:
			{
				strcat(result, " шестьдесят");
				break;
			}
			case 7:
			{
				strcat(result, " семьдесят");
				break;
			}
			case 8:
			{
				strcat(result, " восемьдесят");
				break;
			}
			case 9:
			{
				strcat(result, " девяносто");
				break;
			}
			default:
				break;
		}
	}
	
	if (second == 1)//числа 11-19
	{
		switch (third)
		{
		case 1:
		{
			strcat(result, " одиннадцать");
			break;
		}
		case 2:
		{
			strcat(result, " двенадцать");
			break;
		}
		case 3:
		{
			strcat(result, " тринадцать");
			break;
		}
		case 4:
		{
			strcat(result, " четырнадцать");
			break;
		}
		case 5:
		{
			strcat(result, " пятнадцать");
			break;
		}
		case 6:
		{
			strcat(result, " шестнадцать");
			break;
		}
		case 7:
		{
			strcat(result, " семнадцать");
			break;
		}
		case 8:
		{
			strcat(result, " восемнадцать");
			break;
		}
		case 9:
		{
			strcat(result, " девятнадцать");
			break;
		}
		case 0:
		{
			strcat(result, " десять");
			break;
		}
		default:
			break;
		}
	}

	if (((second!=1)&&(order!=1))||((order==1)&&(third>2)))//печать единиц, если 
	{
		switch (third)
		{
			case 1:
			{
				strcat(result, " один");
				break;
			}
			case 2:
			{
				strcat(result, " два");
				break;
			}
			case 3:
			{
				strcat(result, " три");
				break;
			}
			case 4:
			{
				strcat(result, " четыре");
				break;
			}
			case 5:
			{
				strcat(result, " пять");
				break;
			}
			case 6:
			{
				strcat(result, " шесть");
				break;
			}
			case 7:
			{
				strcat(result, " семь");
				break;
			}
			case 8:
			{
				strcat(result, " восемь");
				break;
			}
			case 9:
			{
				strcat(result, " девять");
				break;
			}
			default:
				break;
		}
	}
	
	if ((order == 1)&&(second!=1))//печать единиц для тысяч
	{
		switch (third)
		{
			case 1:
			{
				strcat(result, " одна");
				break;
			}
			case 2:
			{
				strcat(result, " две");
				break;
			}
			default:
				break;
		}
	}
return result;
}

char* print_velichina(int chislo, int order, char* result)
{
	int first, second, third;
	first = chislo / 100;
	second = chislo / 10 - first * 10;
	third = chislo % 10;
	switch(order)
	{
	case 1:
	{
		if (((third > 4) && (third < 10)) || ((second > 1) && (third == 0)) || (second == 1) || ((third == 0) && (second == 0) && (first != 0)))
		{
			strcat(result, " тысяч");
			break;
		}
		else if (third == 1)
		{
			strcat(result, " тысяча");
			break;
		}
		else if ((third > 1) && (third < 5))
		{
			strcat(result, " тысячи");
			break;
		}
		
		break;
	}
	case 2:
	{
		if (((third > 4) && (third < 10)) || ((second > 1) && (third == 0)) || (second == 1) || ((third == 0) && (second == 0) && (first != 0)))
		{
			strcat(result, " миллионов");
			break;
		}
		else if (third == 1)
		{
			strcat(result, " миллион");
			break;
		}
		else if ((third > 1) && (third < 5))
		{
			strcat(result, " миллиона");
			break;
		}

		break;
		
	}
	case 3:
	{
		if (((third > 4) && (third < 10)) || ((second > 1) && (third == 0)) || (second == 1) || ((third == 0) && (second == 0) && (first != 0)))
		{
			strcat(result, " миллиардов");
			break;
		}
		else if (third == 1)
		{
			strcat(result, " миллиард");
			break;
		}
		else if ((third > 1) && (third < 5))
		{
			strcat(result, " миллиарда");
			break;
		}

		break;
	}
	case 4:
	{
		if (((third > 4) && (third < 10)) || ((second > 1) && (third == 0)) || (second == 1) || ((third == 0) && (second == 0) && (first != 0)))
		{
			strcat(result, " триллионов");
			break;
		}
		else if (third == 1)
		{
			strcat(result, " триллион");
			break;
		}
		else if ((third > 1) && (third < 5))
		{
			strcat(result, " триллиона");
			break;
		}

		break;
	}
	case 5:
	{
		if (((third > 4) && (third < 10)) || ((second > 1) && (third == 0)) || (second == 1) || ((third == 0) && (second == 0) && (first != 0)))
		{
			strcat(result, " квадриллионов");
			break;
		}
		else if (third == 1)
		{
			strcat(result, " квадриллион");
			break;
		}
		else if ((third > 1) && (third < 5))
		{
			strcat(result, " квадраллиона");
			break;
		}

		break;
	}
	case 6:
	{
		if (((third > 4) && (third < 10)) || ((second > 1) && (third == 0)) || (second == 1) || ((third == 0) && (second == 0) && (first != 0)))
		{
			strcat(result, " квинтиллионов");
			break;
		}
		else if (third == 1)
		{
			strcat(result, " квинтиллион");
			break;
		}
		else if ((third > 1) && (third < 5))
		{
			strcat(result, " квинтиллоина");
			break;
		}

		break;
	}
	default:
		break;
	}
	return result;
}