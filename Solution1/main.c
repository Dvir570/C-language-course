// MY FIRST C PROJECT : This project is a Gnim game. Those who empty the piles last - lose.
// Let's see you win the computer ;)

#include <stdio.h>

//return 0 if comp have to start
//return 1 if user have to start
int Meuzan(int a, int b, int c)
{
	if ((a + b == c) || (a + c == b) || (b + c == a))
		return 1;
	else return 0;
}

//return 0 if there no win
//return 1 if  comp win
int compTurn(int *a, int *b, int *c)
{
	if (*a > 1){
		if ((*b == 0 && *c == 0) || (*b == 1 && *c == 1))
		{
			printf("I turned %d to 1\n", *a);
			*a = 1;
			printf("packet sizes are now\n%d, %d, %d\n", *a, *b, *c);
			if ((*a == 1 && *b == 0 && *c == 0) || (*a == 0 && *b == 1 && *c == 0) || (*a == 0 && *b == 0 && *c == 1))
				return 1;
			else return 0;
		}
		if ((*b == 1 && *c == 0) || (*b == 0 && *c == 1))
		{
			printf("I turned %d to 0\n", *a);
			*a = 0;
			printf("packet sizes are now\n%d, %d, %d\n", *a, *b, *c);
			return 1;
		}
		if (*a >= *b && *a >= *c){
			if (*b >= *c){
				printf("I turned %d to %d\n", *a, (*b - *c));
				*a = *b - *c;
				printf("packet sizes are now\n%d, %d, %d\n", *a, *b, *c);
				if ((*a == 1 && *b == 0 && *c == 0) || (*a == 0 && *b == 1 && *c == 0) || (*a == 0 && *b == 0 && *c == 1))
					return 1;
				else return 0;
			}
			else{
				return compTurn(*&a, *&c, *&b);
			}
		}
		else if (*b >= *a && *b >= *c){
			return compTurn(*&b, *&a, *&c);
		}
		else if (*c >= *a && *c >= *b){
			return compTurn(*&c, *&a, *&b);
		}
	}
	else if (*b > 1){
		return compTurn(*&b, *&a, *&c);
	}
	else if (*c > 1)
	{
		return compTurn(*&c, *&b, *&a);
	}
	else if ((*a == 1 && *b == 1 && *c == 0) || (*a == 1 && *b == 0 && *c == 1))
	{
		printf("I turned 1 to 0\n");
		*a = 0;
		printf("packet sizes are now\n%d, %d, %d\n", *a, *b, *c);
		return 1;
	}
	else if (*a == 0 && *b == 1 && *c == 1){
		printf("I turned 1 to 0\n");
		*b = 0;
		printf("packet sizes are now\n%d, %d, %d\n", *a, *b, *c);
		return 1;
	}
	else if (*a == 1 && *b == 1 && *c == 1){
		printf("I turned 1 to 0\n");
		*c = 0;
		printf("packet sizes are now\n%d, %d, %d\n", *a, *b, *c);
		return 0;
	}
}

//return 0 if there no win
//return 1 if  user win
int userTurn(int *a, int *b, int *c){
	int packet, take, valid;
	printf("YOUR TURN!\nplease choose from which packet size you want to take (%d, %d or %d): ", *a, *b, *c);
	valid = scanf("%d", &packet);
	while (valid != 1 || (packet != *a && packet != *b && packet != *c) || packet == 0){
		getchar();
		printf("invalid choose!\nNOTE! you can't choose packet with size 0, char, or packet with size that doesn't exist.\nplease choose again from which packet size you want to take (%d, %d or %d): ", *a, *b, *c);
		valid = scanf("\n\n%d", &packet);
	}

	if (packet == *a){
		printf("your packet size is %d, how much do you want *to take*?", *a);
		valid = scanf("%d", &take);
		while (valid!=1 || take > *a || take <= 0){
			getchar();
			printf("you can't take %d from this packet. please try again:\nyour packet size is %d, how much do you want *to take*?", take, *a);
			valid = scanf("%d", &take);
		}
		printf("you turned %d to %d \n", *a, *a - take);
		*a = *a - take;
		printf("packet sizes are now\n%d, %d, %d\n", *a, *b, *c);
		if ((*a == 1 && *b == 0 && *c == 0) || (*a == 0 && *b == 1 && *c == 0) || (*a == 0 && *b == 0 && *c == 1)){
			return 1;
		}
		return 0;
	}
	if (packet == *b){
		printf("your packet size is %d, how much do you want to take?", *b);
		valid = scanf("%d", &take);
		while (valid != 1 || take > *b || take <= 0){
			getchar();
			printf("you can't take %d from this packet. please try again:\nyour packet size is %d, how much do you want to take?", take, *b);
			valid = scanf("%d", &take);
		}
		printf("you turned %d to %d\n", *b, *b - take);
		*b = *b - take;
		printf("packet sizes are now\n%d, %d, %d\n", *a, *b, *c);
		if ((*a == 1 && *b == 0 && *c == 0) || (*a == 0 && *b == 1 && *c == 0) || (*a == 0 && *b == 0 && *c == 1)){
			return 1;
		}
		return 0;
	}
	if (packet == *c){
		printf("your packet size is %d, how much do you want to take?", *c);
		valid = scanf("%d", &take);
		while (valid != 1 || take > *c || take <= 0){
			getchar();
			printf("you can't take %d from this packet. please try again:\nyour packet size is %d, how much do you want to take?", take, *c);
			valid = scanf("%d", &take);
		}
		printf("you turned %d to %d\n", *c, *c - take);
		*c = *c - take;
		printf("packet sizes are now\n%d, %d, %d\n", *a, *b, *c);
		if ((*a == 1 && *b == 0 && *c == 0) || (*a == 0 && *b == 1 && *c == 0) || (*a == 0 && *b == 0 && *c == 1)){
			return 1;
		}
		return 0;
	}
	return 0;
}

int main()
{
	int play = 1, a, b, c, endGame, des, valid;
	while (play == 1){
		endGame = 0;
		printf("please enter 3 numbers:\n");
		valid = scanf("%d %d %d", &a, &b, &c);
		while (valid!=3 || (a < 0 || b < 0 || c < 0) || (a == 0 && b == 0 && c == 0) || (a == 1 && b == 0 && c == 0) || (a == 0 && b == 1 && c == 0) || (a == 0 && b == 0 && c == 1)){
			getchar();
			printf("invalid input!\nplease enter 3 numbers again: ");
			valid = scanf("%d %d %d", &a, &b, &c);
		}
		printf("packet sizes are\n%d, %d, %d\n", a, b, c);
		if (Meuzan(a, b, c) == 0)
			if (compTurn(&a, &b, &c) == 1){
				printf("YOU LOST!!!\nPRESS 1 to play again\nPRESS 2 to exit\n");
				valid = scanf("%d", &play);
				while (valid!=1 || (play != 1 && play != 2))
				{
					getchar();
					printf("invalid input!\nPRESS 1 to play again\nPRESS 2 to exit\n");
					valid = scanf("%d", &play);
				}
				endGame = 1;
				continue;
			}
		while (endGame == 0){
			if (userTurn(&a, &b, &c) == 1){
				printf("YOU WIN!!!\nPRESS 1 to play again\nPRESS 2 to exit\n");
				valid = scanf("%d", &play);
				while (valid != 1 || (play != 1 && play != 2))
				{
					getchar();
					printf("invalid input!\nPRESS 1 to play again\nPRESS 2 to exit\n");
					valid = scanf("%d", &play);
				}
				endGame = 1;
				continue;
			}
			if (compTurn(&a, &b, &c) == 1){
				printf("YOU LOST!!!\nPRESS 1 to play again\nPRESS 2 to exit\n");
				valid = scanf("%d", &play);
				while (valid != 1 || (play != 1 && play != 2))
				{
					getchar();
					printf("invalid input!\nPRESS 1 to play again\nPRESS 2 to exit\n");
					valid = scanf("%d", &play);
				}
				endGame = 1;
				continue;
			}
		}
	}
	return 0;
}

