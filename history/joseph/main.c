#include<stdlib.h>

#include<stdio.h>

#include<string.h>

#define NEW (struct node*)malloc(sizeof(struct node))



struct node
{
	char name[20];		/*»§Ö÷ÐÕÃû */

	char address[20];	/*µØÖ·(Â¥ºÅ¡¢µ¥ÔªºÅºÍ·¿ºÅÒÔ-žô¿ª) */

	char ID[20];		/*»§Ö÷Éí·ÝÖ€ºÅÂë */

	char date[15];		/*Èë×¡Ê±Œä£šÄêÔÂÈÕÒÔ.žô¿ª£© */

	char type[20];		/*·¿²úÀàÐÍ */

	char fees[20];		/*ÎïÒµ·ÑÓÃ */

	char otherfees[20];	/*ÆäËü·ÑÓÃ */

	char remarks[80];	/*±ž×¢ */

	struct node *next;

};



		/*ÂŒÈë */

struct node *creat(struct node *head)
{
	struct node *p, *q;

	char c;

	if (head == NULL)

		q = NULL;

	else

		for (q = head; q->next != NULL; q = q->next);

	do
	{
		p = NEW;	/*¿ª±ÙÐÂœáµã */

		if (p == NULL)
		{		/* p ÎªNULL,ÐÂœáµã·ÖÅäÊ§°Ü */
			printf("Allocation failure\n");

			exit(1);

		}

		printf("ÇëÊäÈëÐÂ»§Ö÷ÐÅÏ¢\n");
		getchar();

		printf("Inputes name:");

		gets(p->name);

		printf("Inputes address(*-*-***):");

		gets(p->address);

		printf("Inputes ID:");

		gets(p->ID);

		printf("Inputes date(****-**-**):");

		gets(p->date);

		printf("Inputes type:");

		gets(p->type);

		printf("Inputes fees(***.**):");

		gets(p->fees);

		printf("Inputes otherfees(***.**):");

		gets(p->otherfees);

		printf("Inputes remarks:");

		gets(p->remarks);

		p->next = NULL;

		if (q == NULL)
		{
			q = p;

			head = q;
		}

		else

			q->next = p;

		q = p;

		system("cls");	/*ÔËÐÐÇ°ÇåÆÁ */

		printf("ÐÕ    Ãû:%s\n", p->name);

		printf("µØ    Ö·:%s\n", p->address);

		printf("Éí·ÝÖ€ºÅ:%s\n", p->ID);

		printf("·¿ÎÝÀàÐÍ:%s\n", p->type);

		printf("Èë×¡Ê±Œä:%s\n", p->date);

		printf("Îï Òµ ·Ñ:%s\n", p->fees);

		printf("ÆäËû·ÑÓÃ:%s\n", p->otherfees);

		printf("±ž    ×¢:%s\n", p->remarks);

		printf("ŒÌÐøÂŒÈë?(Y or N)\n");

		c = getchar();
		system("cls");



	} while (c == 'Y' || c == 'y');

	return head;

}



																											    /*ä¯ÀÀ */

void prlist(struct node *head)
{
	struct node *p;

	p = head;

	if (p == NULL)

		printf("Ã»ÓÐŒÇÂŒ!\n");

	while (p != NULL)
	{
		printf("ÐÕ    Ãû:%s\n", p->name);

		printf("µØ    Ö·:%s\n", p->address);

		printf("Éí·ÝÖ€ºÅ:%s\n", p->ID);

		printf("·¿ÎÝÀàÐÍ:%s\n", p->type);

		printf("Èë×¡Ê±Œä:%s\n", p->date);

		printf("Îï Òµ ·Ñ:%s\n", p->fees);

		printf("ÆäËû·ÑÓÃ:%s\n", p->otherfees);

		printf("±ž    ×¢:%s\n", p->remarks);

		p = p->next;

	}

}



																																			 /*°Ž»§Ö÷ÐÕÃûÅÅÐò */

struct node *sortlist1(struct node *head)
{
	struct node *p, *q, *temp;

	temp = NEW;		/*¿ª±ÙÐÂœáµã */

	if (temp == NULL)
	{			/* p ÎªNULL,ÐÂœáµã·ÖÅäÊ§°Ü */
		printf("Allocation failure\n");

		exit(1);

	}

	p = q = NULL;

	q = head;

	if (q == NULL);

	else
	 if (q->next == NULL)

		printf("Ö»ÓÐÒ»ÌõŒÇÂŒ!\n");

	else
	{

		for (p = head; q->next != NULL; q = q->next)

			for (p = q->next; p != NULL; p = p->next)

				if (strcmp(q->name, p->name) > 0)
				{
					strcpy(temp->name, q->name);

					strcpy(temp->address, q->address);

					strcpy(temp->ID, q->ID);

					strcpy(temp->date, q->date);

					strcpy(temp->type, q->type);

					strcpy(temp->fees, q->fees);

					strcpy(temp->otherfees,
					       q->otherfees);

					strcpy(temp->remarks, q->remarks);

					strcpy(q->name, p->name);

					strcpy(q->address, p->address);

					strcpy(q->ID, p->ID);

					strcpy(q->date, p->date);

					strcpy(q->type, p->type);

					strcpy(q->fees, p->fees);

					strcpy(q->otherfees, p->otherfees);

					strcpy(q->remarks, p->remarks);

					strcpy(p->name, temp->name);

					strcpy(p->address, temp->address);

					strcpy(p->ID, temp->ID);

					strcpy(p->date, temp->date);

					strcpy(p->type, temp->type);

					strcpy(p->fees, temp->fees);

					strcpy(p->otherfees,
					       temp->otherfees);

					strcpy(p->remarks, temp->remarks);

				}

	}

	prlist(head);

	return head;

}





																																															/*°ŽµØÖ·ÅÅÐò */

struct node *sortlist2(struct node *head)
{
	struct node *p, *q, *temp;

	temp = NEW;		/*¿ª±ÙÐÂœáµã */

	if (temp == NULL)
	{			/* p ÎªNULL,ÐÂœáµã·ÖÅäÊ§°Ü */
		printf("Allocation failure\n");

		exit(1);

	}



	p = q = NULL;

	q = head;

	if (q == NULL);

	else
	 if (q->next == NULL)

		printf("Ö»ÓÐÒ»ÌõŒÇÂŒ!\n");

	else
	{

		for (p = head; q->next != NULL; q = q->next)

			for (p = q->next; p != NULL; p = p->next)

				if (strcmp(q->address, p->address) > 0)
				{
					strcpy(temp->name, q->name);

					strcpy(temp->address, q->address);

					strcpy(temp->ID, q->ID);

					strcpy(temp->date, q->date);

					strcpy(temp->type, q->type);

					strcpy(temp->fees, q->fees);

					strcpy(temp->otherfees,
					       q->otherfees);

					strcpy(temp->remarks, q->remarks);

					strcpy(q->name, p->name);

					strcpy(q->address, p->address);

					strcpy(q->ID, p->ID);

					strcpy(q->date, p->date);

					strcpy(q->type, p->type);

					strcpy(q->fees, p->fees);

					strcpy(q->otherfees, p->otherfees);

					strcpy(q->remarks, p->remarks);

					strcpy(p->name, temp->name);

					strcpy(p->address, temp->address);

					strcpy(p->ID, temp->ID);

					strcpy(p->date, temp->date);

					strcpy(p->type, temp->type);

					strcpy(p->fees, temp->fees);

					strcpy(p->otherfees,
					       temp->otherfees);

					strcpy(p->remarks, temp->remarks);

				}

	}

	prlist(head);

	return head;

}



																																																												     /*°ŽÈë×¡Ê±ŒäÅÅÐò */

struct node *sortlist3(struct node *head)
{
	struct node *p, *q, *temp;

	temp = NEW;		/*¿ª±ÙÐÂœáµã */

	if (temp == NULL)
	{			/* p ÎªNULL,ÐÂœáµã·ÖÅäÊ§°Ü */
		printf("Allocation failure\n");

		exit(1);

	}



	p = q = NULL;

	q = head;

	if (q == NULL);

	else
	 if (q->next == NULL)

		printf("Ö»ÓÐÒ»ÌõŒÇÂŒ!\n");

	else
	{

		for (p = head; q->next != NULL; q = q->next)

			for (p = q->next; p != NULL; p = p->next)

				if (strcmp(q->date, p->date) > 0)
				{
					strcpy(temp->name, q->name);

					strcpy(temp->address, q->address);

					strcpy(temp->ID, q->ID);

					strcpy(temp->date, q->date);

					strcpy(temp->type, q->type);

					strcpy(temp->fees, q->fees);

					strcpy(temp->otherfees,
					       q->otherfees);

					strcpy(temp->remarks, q->remarks);

					strcpy(q->name, p->name);

					strcpy(q->address, p->address);

					strcpy(q->ID, p->ID);

					strcpy(q->date, p->date);

					strcpy(q->type, p->type);

					strcpy(q->fees, p->fees);

					strcpy(q->otherfees, p->otherfees);

					strcpy(q->remarks, p->remarks);

					strcpy(p->name, temp->name);

					strcpy(p->address, temp->address);

					strcpy(p->ID, temp->ID);

					strcpy(p->date, temp->date);

					strcpy(p->type, temp->type);

					strcpy(p->fees, temp->fees);

					strcpy(p->otherfees,
					       temp->otherfees);

					strcpy(p->remarks, temp->remarks);

				}

	}

	prlist(head);

	return head;

}



																																																																										   /*°ŽÐÕÃû²éÕÒ */

struct node *search1(struct node *head, char *name)
{
	struct node *p;

	p = head;

	if (p == NULL)
	{
		system("cls");
		printf("Ã»ÓÐŒÇÂŒ!\n");
	}

	else
	{
		while (strcmp(p->name, name) != 0 && p->next != NULL)

			p = p->next;

		if (strcmp(p->name, name) != 0)

			printf("\nÃ»ÓÐŒÇÂŒ\n");

		else
		{
			printf("\n");

			printf("ÐÕ    Ãû:%s\n", p->name);

			printf("µØ    Ö·:%s\n", p->address);

			printf("Éí·ÝÖ€ºÅ:%s\n", p->ID);

			printf("·¿ÎÝÀàÐÍ:%s\n", p->type);

			printf("Èë×¡Ê±Œä:%s\n", p->date);

			printf("Îï Òµ ·Ñ:%s\n", p->fees);

			printf("ÆäËû·ÑÓÃ:%s\n", p->otherfees);

			printf("±ž    ×¢:%s\n", p->remarks);

		}

	}

	return head;

}



																																																																										   /*°ŽµØÖ·²éÕÒ */

struct node *search2(struct node *head, char *address)
{
	struct node *p;

	p = head;

	if (p == NULL)
	{
		system("cls");
		printf("Ã»ÓÐŒÇÂŒ!\n");
	}

	else
	{
		while (strcmp(p->address, address) != 0 && p->next != NULL)

			p = p->next;

		if (strcmp(p->address, address) != 0)

			printf("\n ÎŽÕÒµœÏàÓŠÁªÏµÈË\n");

		else
		{
			printf("\n");

			printf("ÐÕ    Ãû:%s\n", p->name);

			printf("µØ    Ö·:%s\n", p->address);

			printf("Éí·ÝÖ€ºÅ:%s\n", p->ID);

			printf("·¿ÎÝÀàÐÍ:%s\n", p->type);

			printf("Èë×¡Ê±Œä:%s\n", p->date);

			printf("Îï Òµ ·Ñ:%s\n", p->fees);

			printf("ÆäËû·ÑÓÃ:%s\n", p->otherfees);

			printf("±ž    ×¢:%s\n", p->remarks);

		}

	}

	return head;

}



																																																																										   /*°ŽÈë×¡Ê±Œä²éÕÒ */

struct node *search3(struct node *head, char *date)
{
	struct node *p;

	p = head;

	if (p == NULL)
	{
		system("cls");
		printf("Ã»ÓÐŒÇÂŒ!\n");
	}

	else
	{
		while (strcmp(p->date, date) != 0 && p->next != NULL)

			p = p->next;

		if (strcmp(p->date, date) != 0)

			printf("\n ÎŽÕÒµœÏàÓŠÁªÏµÈË\n");

		else
		{
			printf("\n");

			printf("ÐÕ    Ãû:%s\n", p->name);

			printf("µØ    Ö·:%s\n", p->address);

			printf("Éí·ÝÖ€ºÅ:%s\n", p->ID);

			printf("·¿ÎÝÀàÐÍ:%s\n", p->type);

			printf("Èë×¡Ê±Œä:%s\n", p->date);

			printf("Îï Òµ ·Ñ:%s\n", p->fees);

			printf("ÆäËû·ÑÓÃ:%s\n", p->otherfees);

			printf("±ž    ×¢:%s\n", p->remarks);

		}

	}

	return head;

}





																																																																										   /*°ŽÐÕÃûÉŸ³ýÐÅÏ¢ */

struct node *delnode1(struct node *head, char *name)
{
	struct node *p, *q;

	if (head == NULL)
	{
		system("cls");
		printf("Ã»ÓÐŒÇÂŒ!\n");

		return head;

	}

	p = head;

	while (strcmp(name, p->name) != 0 && p->next != NULL)
	{
		q = p;

		p = p->next;

	}

	if (strcmp(name, p->name) == 0)
	{
		if (p == head)

			head = p->next;

		else

			q->next = p->next;

		free(p);

		system("cls");
		printf("ÉŸ³ý³É¹Š!\n");

	}

	else
	{
		system("cls");
		printf("Ã»ÓÐŒÇÂŒ!\n");
	}

	return head;

}



																																																																											      /*°ŽµØÖ·ÉŸ³ýÐÅÏ¢ */

struct node *delnode2(struct node *head, char *address)
{
	struct node *p, *q;

	if (head == NULL)
	{
		system("cls");
		printf("Ã»ÓÐŒÇÂŒ!\n");

		return head;

	}

	p = head;

	while (strcmp(address, p->address) != 0 && p->next != NULL)
	{
		q = p;

		p = p->next;

	}

	if (strcmp(address, p->address) == 0)
	{
		if (p == head)

			head = p->next;

		else

			q->next = p->next;

		free(p);

		system("cls");
		printf("ÉŸ³ý³É¹Š!\n");

	}

	else
	{
		system("cls");
		printf("Ã»ÓÐŒÇÂŒ!\n");
	}

	return head;

}





																																																																													 /*°ŽÈë×¡Ê±ŒäÉŸ³ýÐÅÏ¢ */

struct node *delnode3(struct node *head, char *date)
{
	struct node *p, *q;

	if (head == NULL)
	{
		system("cls");
		printf("Ã»ÓÐŒÇÂŒ!\n");

		return head;

	}

	p = head;

	while (strcmp(date, p->date) != 0 && p->next != NULL)
	{
		q = p;

		p = p->next;

	}

	if (strcmp(date, p->date) == 0)
	{
		if (p == head)

			head = p->next;

		else

			q->next = p->next;

		free(p);

		system("cls");
		printf("ÉŸ³ý³É¹Š!\n");

	}

	else
	{
		system("cls");
		printf("Ã»ÓÐŒÇÂŒ!\n");
	}

	return head;

}





																																																																														   /*°ŽÐÕÃû²éÕÒÐÞžÄÐÅÏ¢ */

struct node *modify1(struct node *head, char *name)
{
	struct node *p;

	p = head;

	char address1[20], name1[20], ID[20], type[20], date1[15],
	    remarks[80], c;

	char fees[20], otherfees[20];

	int i;

	if (p == NULL)
	{
		system("cls");
		printf("Ã»ÓÐŒÇÂŒ!\n");
	}

	else
	{
		while (strcmp(p->name, name) != 0 && p->next != NULL)

			p = p->next;

		if (strcmp(p->name, name) != 0)
		{
			system("cls");
			printf("\nÃ»ÓÐŒÇÂŒ!\n");
		}

		else
		{
			printf
			    ("ÐÕ    Ãû:%s\nµØ    Ö·:%s\nÉí·ÝÖ€ºÅ:%s\n·¿ÎÝÀàÐÍ:%s\nÈë×¡Ê±Œä:%s\nÎï Òµ ·Ñ:%s\nÆäËû·ÑÓÃ:%s\n±ž    ×¢:%s\n",
			     p->name, p->address, p->ID, p->type, p->date,
			     p->fees, p->otherfees, p->remarks);

			printf("È·ÈÏÐÞžÄ?(Y or N)");

			getchar();
			c = getchar();
			system("cls");	/*ÔËÐÐÇ°ÇåÆÁ */



			while (c == 'Y' || c == 'y')
			{
				do
				{																																																																															       /*****ÏÔÊŸ²Ëµ¥*****/

					printf
					    ("=====ÎïÒµÐÅÏ¢¹ÜÀíÐÞžÄÏîÄ¿=====\n");

					printf
					    ("--------------------------------\n");

					printf
					    (" 1£º»§Ö÷ÐÕÃû               5£ºÈë×¡Ê±Œä\n");

					printf
					    (" 2£ºµØÖ·                   6£ºÎïÒµ·Ñ\n");

					printf
					    (" 3£ºÉí·ÝÖ€                 7£ºÆäËü·ÑÓÃ\n");

					printf
					    (" 4£º·¿²úÀàÐÍ               8£º±ž×¢\n");

					printf
					    ("--------------------------------\n");

					printf
					    ("ÇëÄúÔÚÉÏÊö¹ŠÄÜÖÐÑ¡Ôñ(1-8):\n");

					scanf("%d", &i);
					system("cls");	/*ÔËÐÐÇ°ÇåÆÁ */



				} while (i < 1 || i > 8);

				switch (i)
				{
				case 1:{
						printf
						    ("The correct name is:");

						scanf("%s", name1);

						strcpy(p->name, name1);
						break;
					}



				case 2:{
						printf
						    ("The correct address is:");

						scanf("%s", address1);

						strcpy(p->address,
						       address1);
						break;
					}



				case 3:{
						printf
						    ("The correct ID is:");

						scanf("%s", &ID);

						strcpy(p->ID, ID);
						break;
					}



				case 4:{
						printf
						    ("The correct type is:");

						scanf("%s", type);

						strcpy(p->type, type);

						break;
					}



				case 5:{
						printf
						    ("The correct date is:");

						scanf("%s", date1);

						strcpy(p->date, date1);
						break;
					}



				case 6:{
						printf
						    ("The correct fees is:");

						scanf("%s", fees);

						strcpy(p->fees, fees);
						break;
					}





				case 7:{
						printf
						    ("The correct otherfees is:");

						scanf("%s", otherfees);

						strcpy(p->otherfees,
						       otherfees);
						break;
					}

				case 8:{
						printf
						    ("The correct remarks is:");

						scanf("%s", remarks);

						strcpy(p->remarks,
						       remarks);
						break;
					}

				}

				getchar();
				printf
				    ("ŒÌÐøÐÞžÄ±Ÿ»§Ö÷ÐÅÏ¢?(Y or N)");

				scanf("%c", &c);
				system("cls");	/*ÔËÐÐÇ°ÇåÆÁ */



			}





			printf("µØ    Ö·:%s\n", p->address);

			printf("ÐÕ    Ãû:%s\n", p->name);

			printf("Éí·ÝÖ€ºÅ:%s\n", p->ID);

			printf("·¿ÎÝÀàÐÍ:%s\n", p->type);

			printf("Èë×¡Ê±Œä:%s\n", p->date);

			printf("Îï Òµ ·Ñ:%s\n", p->fees);

			printf("ÆäËû·ÑÓÃ:%s\n", p->otherfees);

			printf("±ž    ×¢:%s\n", p->remarks);

		}

	}

	return head;



}





																																																																																																																																    /*°ŽµØÖ·²éÕÒÐÞžÄÐÅÏ¢ */

struct node *modify2(struct node *head, char *address)
{
	struct node *p;

	p = head;

	char address1[20], name1[20], ID[20], type[20], date1[15],
	    remarks[80], c;

	char fees[20], otherfees[20];

	int i;

	if (p == NULL)
	{
		system("cls");
		printf("Ã»ÓÐŒÇÂŒ!\n");
	}

	else
	{
		while (strcmp(p->address, address) != 0 && p->next != NULL)

			p = p->next;

		if (strcmp(p->address, address) != 0)
		{
			system("cls");
			printf("\nÃ»ÓÐŒÇÂŒ!\n");
		}

		else
		{
			printf
			    ("ÐÕ    Ãû:%s\nµØ    Ö·:%s\nÉí·ÝÖ€ºÅ:%s\n·¿ÎÝÀàÐÍ:%s\nÈë×¡Ê±Œä:%s\nÎï Òµ ·Ñ:%s\nÆäËû·ÑÓÃ:%s\n±ž    ×¢:%s\n",
			     p->name, p->address, p->ID, p->type, p->date,
			     p->fees, p->otherfees, p->remarks);

			printf("È·ÈÏÐÞžÄ?(Y or N)");



			getchar();
			c = getchar();
			system("cls");	/*ÔËÐÐÇ°ÇåÆÁ */

			while (c == 'Y' || c == 'y')
			{
				do
				{																																																																																																																																		      /*****ÏÔÊŸ²Ëµ¥*****/

					printf
					    ("=====ÎïÒµÐÅÏ¢¹ÜÀíÐÞžÄÏîÄ¿=====\n");

					printf
					    ("--------------------------------\n");

					printf
					    (" 1£º»§Ö÷ÐÕÃû               5£º·¿²úÀàÐÍ\n");

					printf
					    (" 2£ºµØÖ·                   6£ºÎïÒµ·Ñ\n");

					printf
					    (" 3£ºÉí·ÝÖ€                 7£ºÆäËü·ÑÓÃ\n");

					printf
					    (" 4£ºÈë×¡Ê±Œä               8£º±ž×¢\n");

					printf
					    ("--------------------------------\n");

					printf
					    ("ÇëÄúÔÚÉÏÊö¹ŠÄÜÖÐÑ¡Ôñ(1-8):\n");

					scanf("%d", &i);

				} while (i < 1 || i > 8);

				switch (i)
				{
				case 1:{
						printf
						    ("The correct name is:");

						scanf("%s", name1);

						strcpy(p->name, name1);
						break;
					}



				case 2:{
						printf
						    ("The correct address is:");

						scanf("%s", address1);

						strcpy(p->address,
						       address1);
						break;
					}



				case 3:{
						printf
						    ("The correct ID is:");

						scanf("%s", &ID);

						strcpy(p->ID, ID);
						break;
					}



				case 4:{
						printf
						    ("The correct type is:");

						scanf("%s", type);

						strcpy(p->type, type);

						break;
					}

				case 5:{
						printf
						    ("The correct date is:");

						scanf("%s", date1);

						strcpy(p->date, date1);
						break;
					}



				case 6:{
						printf
						    ("The correct fees is:");

						scanf("%s", fees);

						strcpy(p->fees, fees);
						break;
					}





				case 7:{
						printf
						    ("The correct otherfees is:");

						scanf("%s", otherfees);

						strcpy(p->otherfees,
						       otherfees);
						break;
					}

				case 8:{
						printf
						    ("The correct remarks is:");

						scanf("%s", remarks);

						strcpy(p->remarks,
						       remarks);
						break;
					}

				}

				printf
				    ("ŒÌÐøÐÞžÄ±Ÿ»§Ö÷ÐÅÏ¢?(Y or N)");



				getchar();
				scanf("%c", &c);
				system("cls");	/*ÔËÐÐÇ°ÇåÆÁ */

			}

			printf("µØ    Ö·:%s\n", p->address);

			printf("ÐÕ    Ãû:%s\n", p->name);

			printf("Éí·ÝÖ€ºÅ:%s\n", p->ID);

			printf("·¿ÎÝÀàÐÍ:%s\n", p->type);

			printf("Èë×¡Ê±Œä:%s\n", p->date);

			printf("Îï Òµ ·Ñ:%s\n", p->fees);

			printf("ÆäËû·ÑÓÃ:%s\n", p->otherfees);

			printf("±ž    ×¢:%s\n", p->remarks);

		}

	}

	return head;



}







																																																																																																																																																																																			     /*°ŽÈë×¡Ê±Œä²éÕÒÐÞžÄÐÅÏ¢ */

struct node *modify3(struct node *head, char *date)
{
	struct node *p;

	p = head;

	char address1[20], name1[20], ID[20], type[20], date1[15],
	    remarks[80], c;

	char fees[20], otherfees[20];

	int i;

	if (p == NULL)
	{
		system("cls");
		printf("Ã»ÓÐŒÇÂŒ!\n");
	}

	else
	{
		while (strcmp(p->date, date) != 0 && p->next != NULL)

			p = p->next;

		if (strcmp(p->date, date) != 0)
		{
			system("cls");
			printf("\nÃ»ÓÐŒÇÂŒ!\n");
		}

		else
		{
			printf
			    ("ÐÕ    Ãû:%s\nµØ    Ö·:%s\nÉí·ÝÖ€ºÅ:%s\n·¿ÎÝÀàÐÍ:%s\nÈë×¡Ê±Œä:%s\nÎï Òµ ·Ñ:%s\nÆäËû·ÑÓÃ:%s\n±ž    ×¢:%s\n",
			     p->name, p->address, p->ID, p->type, p->date,
			     p->fees, p->otherfees, p->remarks);

			printf("È·ÈÏÐÞžÄ?(Y or N)");



			getchar();
			c = getchar();
			system("cls");	/*ÔËÐÐÇ°ÇåÆÁ */

			while (c == 'Y' || c == 'y')
			{
				do
				{																																																																																																																																																																																					      /*****ÏÔÊŸ²Ëµ¥*****/

					printf
					    ("=====ÎïÒµÐÅÏ¢¹ÜÀíÐÞžÄÏîÄ¿=====\n");

					printf
					    ("--------------------------------\n");

					printf
					    (" 1£º»§Ö÷ÐÕÃû               5£º·¿²úÀàÐÍ\n");

					printf
					    (" 2£ºµØÖ·                   6£ºÎïÒµ·Ñ\n");

					printf
					    (" 3£ºÉí·ÝÖ€                 7£ºÆäËü·ÑÓÃ\n");

					printf
					    (" 4£ºÈë×¡Ê±Œä               8£º±ž×¢\n");

					printf
					    ("--------------------------------\n");

					printf
					    ("ÇëÄúÔÚÉÏÊö¹ŠÄÜÖÐÑ¡Ôñ(1-8):\n");

					scanf("%d", &i);

				} while (i < 1 || i > 8);
				system("cls");

				switch (i)
				{
				case 1:{
						printf
						    ("The correct name is:");

						scanf("%s", name1);

						strcpy(p->name, name1);
						break;
					}



				case 2:{
						printf
						    ("The correct address is:");

						scanf("%s", address1);

						strcpy(p->address,
						       address1);
						break;
					}



				case 3:{
						printf
						    ("The correct ID is:");

						scanf("%s", &ID);

						strcpy(p->ID, ID);
						break;
					}



				case 4:{
						printf
						    ("The correct type is:");

						scanf("%s", type);

						strcpy(p->type, type);

						break;
					}



				case 5:{
						printf
						    ("The correct date is:");

						scanf("%s", date1);

						strcpy(p->date, date1);
						break;
					}



				case 6:{
						printf
						    ("The correct fees is:");

						scanf("%s", fees);

						strcpy(p->fees, fees);
						break;
					}





				case 7:{
						printf
						    ("The correct otherfees is:");

						scanf("%s", otherfees);

						strcpy(p->otherfees,
						       otherfees);
						break;
					}

				case 8:{
						printf
						    ("The correct remarks is:");

						scanf("%s", remarks);

						strcpy(p->remarks,
						       remarks);
						break;
					}

				}

				printf
				    ("ŒÌÐøÐÞžÄ±Ÿ»§Ö÷ÐÅÏ¢?(Y or N)");

				getchar();
				scanf("%c", &c);
				system("cls");	/*ÔËÐÐÇ°ÇåÆÁ */



			}

			printf("µØ    Ö·:%s\n", p->address);

			printf("ÐÕ    Ãû:%s\n", p->name);

			printf("Éí·ÝÖ€ºÅ:%s\n", p->ID);

			printf("·¿ÎÝÀàÐÍ:%s\n", p->type);

			printf("Èë×¡Ê±Œä:%s\n", p->date);

			printf("Îï Òµ ·Ñ:%s\n", p->fees);

			printf("ÆäËû·ÑÓÃ:%s\n", p->otherfees);

			printf("±ž    ×¢:%s\n", p->remarks);

		}

	}

	return head;



}





																																																																																																																																																																																																																																					  /*°ŽÐÕÃû²éÑ¯²åÈë */

struct node *insert1(struct node *head, struct node *p0, char *name)
{
	struct node *p, *q;

	if (head == NULL)
	{
		head = p0;

		p0->next = NULL;

		system("cls");

		printf
		    ("Ã»ÓÐŒÇÂŒ£¬ÐÂ»§Ö÷²åÈëµœ×îºó!\n");

		printf("ÐÕ    Ãû:%s\n", p0->name);

		printf("µØ    Ö·:%s\n", p0->address);

		printf("Éí·ÝÖ€ºÅ:%s\n", p0->ID);

		printf("·¿ÎÝÀàÐÍ:%s\n", p0->type);

		printf("Èë×¡Ê±Œä:%s\n", p0->date);

		printf("Îï Òµ ·Ñ:%s\n", p0->fees);

		printf("ÆäËû·ÑÓÃ:%s\n", p0->otherfees);

		printf("±ž    ×¢:%s\n", p0->remarks);

	}

	else
	{
		p = head;

		while (strcmp(name, p->name) != 0 && p->next != NULL)
		{
			q = p;
			p = q->next;
		}

		if (strcmp(name, p->name) == 0)
		{
			if (p == head)
			{
				head = p0;	/*ÔÚ±íÍ·²åÈëœáµã */

				p0->next = p;

			}

			else
			{
				q->next = p0;	/*ÔÚ±íÖÐŒä²åÈëœáµã */

				p0->next = p;

			}

			system("cls");	/*ÔËÐÐÇ°ÇåÆÁ */

			printf("²åÈë³É¹Š!\n");

			printf("ÐÕ    Ãû:%s\n", p0->name);

			printf("µØ    Ö·:%s\n", p0->address);

			printf("Éí·ÝÖ€ºÅ:%s\n", p0->ID);

			printf("·¿ÎÝÀàÐÍ:%s\n", p0->type);

			printf("Èë×¡Ê±Œä:%s\n", p0->date);

			printf("Îï Òµ ·Ñ:%s\n", p0->fees);

			printf("ÆäËû·ÑÓÃ:%s\n", p0->otherfees);

			printf("±ž    ×¢:%s\n", p0->remarks);

		}

		else
		{
			p->next = p0;	/*ÔÚ±íÎ²²åÈëœáµã */

			p0->next = NULL;

			system("cls");

			printf
			    ("Ã»ÓÐŒÇÂŒ£¬ÐÂ»§Ö÷²åÈëµœ×îºó!\n");

			printf("ÐÕ    Ãû:%s\n", p0->name);

			printf("µØ    Ö·:%s\n", p0->address);

			printf("Éí·ÝÖ€ºÅ:%s\n", p0->ID);

			printf("·¿ÎÝÀàÐÍ:%s\n", p0->type);

			printf("Èë×¡Ê±Œä:%s\n", p0->date);

			printf("Îï Òµ ·Ñ:%s\n", p0->fees);

			printf("ÆäËû·ÑÓÃ:%s\n", p0->otherfees);

			printf("±ž    ×¢:%s\n", p0->remarks);



		}



	}

	return head;

}





																																																																																																																																																																																																																																																																									   /*°ŽµØÖ·²éÑ¯²åÈë */

struct node *insert2(struct node *head, struct node *p0, char *address)
{
	struct node *p, *q;

	if (head == NULL)
	{
		head = p0;

		p0->next = NULL;

		system("cls");

		printf
		    ("Ã»ÓÐŒÇÂŒ£¬ÐÂ»§Ö÷²åÈëµœ×îºó!\n");

		printf("ÐÕ    Ãû:%s\n", p0->name);

		printf("µØ    Ö·:%s\n", p0->address);

		printf("Éí·ÝÖ€ºÅ:%s\n", p0->ID);

		printf("·¿ÎÝÀàÐÍ:%s\n", p0->type);

		printf("Èë×¡Ê±Œä:%s\n", p0->date);

		printf("Îï Òµ ·Ñ:%s\n", p0->fees);

		printf("ÆäËû·ÑÓÃ:%s\n", p0->otherfees);

		printf("±ž    ×¢:%s\n", p0->remarks);

	}

	else
	{
		p = head;

		while (strcmp(address, p->address) != 0 && p->next != NULL)
		{
			q = p;
			p = q->next;
		}

		if (strcmp(address, p->address) == 0)
		{
			if (p == head)
			{
				head = p0;	/*ÔÚ±íÍ·²åÈëœáµã */

				p0->next = p;

			}

			else
			{
				q->next = p0;	/*ÔÚ±íÖÐŒä²åÈëœáµã */

				p0->next = p;

			}

			system("cls");

			printf("²åÈë³É¹Š!\n");

			printf("ÐÕ    Ãû:%s\n", p0->name);

			printf("µØ    Ö·:%s\n", p0->address);

			printf("Éí·ÝÖ€ºÅ:%s\n", p0->ID);

			printf("·¿ÎÝÀàÐÍ:%s\n", p0->type);

			printf("Èë×¡Ê±Œä:%s\n", p0->date);

			printf("Îï Òµ ·Ñ:%s\n", p0->fees);

			printf("ÆäËû·ÑÓÃ:%s\n", p0->otherfees);

			printf("±ž    ×¢:%s\n", p0->remarks);

		}

		else
		{
			p->next = p0;	/*ÔÚ±íÎ²²åÈëœáµã */

			p0->next = NULL;

			system("cls");

			printf
			    ("Ã»ÓÐŒÇÂŒ£¬ÐÂ»§Ö÷²åÈëµœ×îºó!\n");

			printf("ÐÕ    Ãû:%s\n", p0->name);

			printf("µØ    Ö·:%s\n", p0->address);

			printf("Éí·ÝÖ€ºÅ:%s\n", p0->ID);

			printf("·¿ÎÝÀàÐÍ:%s\n", p0->type);

			printf("Èë×¡Ê±Œä:%s\n", p0->date);

			printf("Îï Òµ ·Ñ:%s\n", p0->fees);

			printf("ÆäËû·ÑÓÃ:%s\n", p0->otherfees);

			printf("±ž    ×¢:%s\n", p0->remarks);

		}



	}

	return head;

}





																																																																																																																																																																																																																																																																																																													       /*°ŽÈë×¡Ê±Œä²éÑ¯²åÈë */

struct node *insert3(struct node *head, struct node *p0, char *date)
{
	struct node *p, *q;

	if (head == NULL)
	{
		head = p0;

		p0->next = NULL;

		system("cls");

		printf
		    ("Ã»ÓÐŒÇÂŒ£¬ÐÂ»§Ö÷²åÈëµœ×îºó!\n");

		printf("ÐÕ    Ãû:%s\n", p0->name);

		printf("µØ    Ö·:%s\n", p0->address);

		printf("Éí·ÝÖ€ºÅ:%s\n", p0->ID);

		printf("·¿ÎÝÀàÐÍ:%s\n", p0->type);

		printf("Èë×¡Ê±Œä:%s\n", p0->date);

		printf("Îï Òµ ·Ñ:%s\n", p0->fees);

		printf("ÆäËû·ÑÓÃ:%s\n", p0->otherfees);

		printf("±ž    ×¢:%s\n", p0->remarks);

	}

	else
	{
		p = head;

		while (strcmp(date, p->date) != 0 && p->next != NULL)
		{
			q = p;
			p = q->next;
		}

		if (strcmp(date, p->date) == 0)
		{
			if (p == head)
			{
				head = p0;	/*ÔÚ±íÍ·²åÈëœáµã */

				p0->next = p;

			}

			else
			{
				q->next = p0;	/*ÔÚ±íÖÐŒä²åÈëœáµã */

				p0->next = p;

			}

			system("cls");

			printf("²åÈë³É¹Š!\n");

			printf("ÐÕ    Ãû:%s\n", p0->name);

			printf("µØ    Ö·:%s\n", p0->address);

			printf("Éí·ÝÖ€ºÅ:%s\n", p0->ID);

			printf("·¿ÎÝÀàÐÍ:%s\n", p0->type);

			printf("Èë×¡Ê±Œä:%s\n", p0->date);

			printf("Îï Òµ ·Ñ:%s\n", p0->fees);

			printf("ÆäËû·ÑÓÃ:%s\n", p0->otherfees);

			printf("±ž    ×¢:%s\n", p0->remarks);

		}

		else
		{
			p->next = p0;	/*ÔÚ±íÎ²²åÈëœáµã */

			p0->next = NULL;

			system("cls");

			printf
			    ("Ã»ÓÐŒÇÂŒ£¬ÐÂ»§Ö÷²åÈëµœ×îºó!\n");

			printf("ÐÕ    Ãû:%s\n", p0->name);

			printf("µØ    Ö·:%s\n", p0->address);

			printf("Éí·ÝÖ€ºÅ:%s\n", p0->ID);

			printf("·¿ÎÝÀàÐÍ:%s\n", p0->type);

			printf("Èë×¡Ê±Œä:%s\n", p0->date);

			printf("Îï Òµ ·Ñ:%s\n", p0->fees);

			printf("ÆäËû·ÑÓÃ:%s\n", p0->otherfees);

			printf("±ž    ×¢:%s\n", p0->remarks);

		}



	}

	return head;

}





																																																																																																																																																																																																																																																																																																																																																			     /*±£Žæ */

void save(struct node *head)
{
	FILE *fp;

	struct node *p;

	p = head;

	if (p == NULL)

		printf("Ã»ÓÐŒÇÂŒ£¬ÎÞ·šŽ¢Žæ!\n");

	else {

		if ((fp = fopen("d:\\filename.txt", "w")) == NULL)


		{		/*ÐÂœš²¢Žò¿ªÒ»žöÎÄŒþ£¬Í¬Ê±²âÊÔÊÇ·ñ³É¹Š */
			printf("Can't open  filename.txt\n");

			exit(1);

		}

		else {

			for (; p != NULL; p = p->next)
			{

				fputs(p->name, fp);

				fputs("\n", fp);

				fputs(p->address, fp);

				fputs("\n", fp);

				fputs(p->ID, fp);

				fputs("\n", fp);

				fputs(p->date, fp);

				fputs("\n", fp);

				fputs(p->type, fp);

				fputs("\n", fp);

				fputs(p->fees, fp);

				fputs("\n", fp);

				fputs(p->otherfees, fp);

				fputs("\n", fp);

				fputs(p->remarks, fp);

				fputs("\n", fp);



			}



			printf("±£ŽæÍê±Ï!\n");



			fclose(fp);	/*œšÁ¢ÎÄŒþœáÊø£¬¹Ø±ÕÎÄŒþ */

		}

	}

}





																																																																																																																																																																																																																																																																																																																																																																																		     /*Ö÷º¯Êý */

int main()
{
	system("cls");		/*ÔËÐÐÇ°ÇåÆÁ */

	int w = 1;
	char password[20] = "guolilong", s[20], l;

	do
	{
		if (w == 1)
		{
			printf
			    ("**********¹ÜÀíÔ±µÇÂŒ**********\n");

			printf("ÇëÄúÊäÈëÃÜÂë:\n");

			gets(s);

			system("cls");
		}

		if (w == 0)
		{
			printf("ÇëÄúÊäÈëÃÜÂë:\n");

			getchar();

			gets(s);

			system("cls");
		}

		if (strcmp(password, s) == 0)
		{
			w = 1;
			l = 'n';
		}

		else
		{
			w = 0;

			printf
			    ("ÃÜÂëŽíÎó£¬ŒÌÐøÊäÈë?(Y or N)\n");

			l = getchar();

			system("cls");

		}

	} while (l == 'Y' || l == 'y');

	system("cls");



	if (w)
	{
		struct node *head = NULL, *per;

		int c;
		char name[20], address[20], date[15], m;

		do
		{
			do
			{																																																																																																																																																																																																																																																																																																																																																																																												       /*****ÏÔÊŸ²Ëµ¥*****/

				printf
				    ("**************ÎïÒµÐÅÏ¢¹ÜÀíÏµÍ³*************\n");

				printf
				    ("--------------------------------------------\n");

				printf
				    (" 1£ºÂŒÈë»§Ö÷ÐÅÏ¢               5£ºÉŸ³ý»§Ö÷\n");

				printf
				    (" 2£ºÏÔÊŸ»§Ö÷ÐÅÏ¢               6£ºÐÞžÄ»§Ö÷ÐÅÏ¢\n");

				printf
				    (" 3£ºÅÅÐò»§Ö÷ÐÅÏ¢               7£º²åÈëÐÂ»§Ö÷\n");

				printf
				    (" 4£º²éÕÒ»§Ö÷                   8£º±£Žæ»§Ö÷ÐÅÏ¢\n");

				printf
				    ("              0£ºÍË³öÏµÍ³\n");

				printf
				    ("--------------------------------------------\n");

				printf
				    ("ÇëÄúÔÚÉÏÊö¹ŠÄÜÖÐÑ¡Ôñ(0-8):\n");

				scanf("%d", &c);

			} while (c < 0 || c > 8);
			system("cls");	/*ÔËÐÐÇ°ÇåÆÁ */



																																																																																																																																																																																																																																																																																																																																																																																																					/*****ÓÃ»§Ñ¡Ôñ²¢×ª»»ÏàÓŠº¯Êý*****/



			switch (c)
			{
			case 0:
				exit(0);
				break;

			case 1:
				head = creat(head);
				break;

			case 2:
				prlist(head);
				break;

			case 3:																																																																																																																																																																																																																																																																																																																																																																																																				 /*****ÏÔÊŸÅÅÐò×Ó²Ëµ¥*****/

				do {

					do {
						printf
						    ("*****************ÅÅÐò****************\n");

						printf
						    ("-------------------------------------\n");

						printf
						    (" 1£º°Ž»§Ö÷ÐÕÃû           3£º°ŽÈë×¡Ê±Œä\n");

						printf
						    (" 2£º°ŽµØÖ·  \n");

						printf
						    ("--------------------------------------\n");

						printf
						    ("ÇëÄúÔÚÉÏÊö¹ŠÄÜÖÐÑ¡Ôñ(1-3):\n");

						scanf("%d", &c);

					} while (c < 1 || c > 3);
					system("cls");	/*ÔËÐÐÇ°ÇåÆÁ */



					switch (c)
					{
					case 1:
						sortlist1(head);
						break;

					case 2:
						sortlist2(head);
						break;

					case 3:
						sortlist3(head);
						break;

					}

					getchar();

					printf
					    ("ŒÌÐø°ŽÆäËü×Ö¶ÎÅÅÐò?(Y or N)\n");

					scanf("%c", &m);
					system("cls");	/*ÔËÐÐÇ°ÇåÆÁ */

				} while (m == 'Y' || m == 'y');
				break;





			case 4:																																																																																																																																																																																																																																																																																																																																																																																																																							    /*****ÏÔÊŸ²éÕÒ×Ó²Ëµ¥*****/

				do {

					do {
						printf
						    ("********************²éÕÒ*****************\n");

						printf
						    ("----------------------------------------\n");

						printf
						    (" 1£º°Ž»§Ö÷ÐÕÃû              3£º°ŽÈë×¡Ê±Œä\n");

						printf
						    (" 2£º°ŽµØÖ· \n");

						printf
						    ("-----------------------------------------\n");

						printf
						    ("ÇëÄúÔÚÉÏÊö¹ŠÄÜÖÐÑ¡Ôñ(1-3):\n");

						scanf("%d", &c);

					} while (c < 1 || c > 3);
					system("cls");

					switch (c)
					{
					case 1:
						printf
						    (" ÊäÈëÒª²éÕÒµÄÐÕÃû\n");

						scanf("%s", name);

						search1(head, name);
						break;

					case 2:
						printf
						    (" ÊäÈëÒª²éÕÒµÄµØÖ·\n");

						scanf("%s", address);

						search2(head, address);
						break;

					case 3:
						printf
						    (" ÊäÈëÒª²éÕÒµÄÈë×¡Ê±Œä\n");

						scanf("%s", date);

						search3(head, date);
						break;

					}

					getchar();

					printf
					    ("ŒÌÐø²éÕÒ?(Y or N)\n");

					scanf("%c", &m);
					system("cls");	/*ÔËÐÐÇ°ÇåÆÁ */



				} while (m == 'Y' || m == 'y');
				break;







			case 5:																																																																																																																																																																																																																																																																																																																																																																																																																																																					   /*****ÏÔÊŸÉŸ³ý×Ó²Ëµ¥*****/

				do {

					do {
						printf
						    ("****************ÉŸ³ý******************\n");

						printf
						    ("--------------------------------------\n");

						printf
						    (" 1£º°Ž»§Ö÷ÐÕÃû              3£º°ŽÈë×¡Ê±Œä\n");

						printf
						    (" 2£º°ŽµØÖ· \n");

						printf
						    ("---------------------------------------\n");

						printf
						    ("ÇëÄúÔÚÉÏÊö¹ŠÄÜÖÐÑ¡Ôñ(1-3):\n");

						scanf("%d", &c);

					} while (c < 1 || c > 3);
					system("cls");

					switch (c)
					{
					case 1:
						printf
						    (" ÊäÈëÒªÉŸ³ýµÄÐÕÃû\n");

						scanf("%s", name);

						head =
						    delnode1(head, name);
						break;

					case 2:
						printf
						    (" ÊäÈëÒªÉŸ³ýµÄµØÖ·\n");

						scanf("%s", address);

						head =
						    delnode2(head,
							     address);
						break;

					case 3:
						printf
						    (" ÊäÈëÒªÉŸ³ýµÄÈë×¡Ê±Œä\n");

						scanf("%s", date);

						head =
						    delnode3(head, date);
						break;

					}

					getchar();

					printf
					    ("ŒÌÐøÉŸ³ýÆäËü»§Ö÷?(Y or N)\n");

					scanf("%c", &m);
					system("cls");	/*ÔËÐÐÇ°ÇåÆÁ */



				} while (m == 'Y' || m == 'y');
				break;





			case 6:																																																																																																																																																																																																																																																																																																																																																																																																																																																																																			    /*****ÏÔÊŸÐÞžÄ×Ó²Ëµ¥*****/

				do {

					do {
						printf
						    ("**********************ÐÞžÄ***********************\n");

						printf
						    ("-----------------------------------------------\n");

						printf
						    (" 1£º°Ž»§Ö÷ÐÕÃû²éÕÒÐÞžÄ     3£º°ŽÈë×¡Ê±Œä²éÕÒÐÞžÄ\n");

						printf
						    (" 2£º°ŽµØÖ·²éÕÒÐÞžÄ \n");

						printf
						    ("------------------------------------------------\n");

						printf
						    ("ÇëÄúÔÚÉÏÊö¹ŠÄÜÖÐÑ¡Ôñ(1-3):\n");

						scanf("%d", &c);

					} while (c < 1 || c > 3);
					system("cls");

					switch (c)
					{
					case 1:
						printf
						    (" ÊäÈëÒªÐÞžÄµÄÐÕÃû\n");

						scanf("%s", name);

						head = modify1(head, name);
						break;

					case 2:
						printf
						    (" ÊäÈëÒªÐÞžÄµÄµØÖ·\n");

						scanf("%s", address);

						head =
						    modify2(head, address);
						break;

					case 3:
						printf
						    (" ÊäÈëÒªÐÞžÄµÄÈë×¡Ê±Œä\n");

						scanf("%s", date);

						head = modify3(head, date);
						break;

					}

					getchar();

					printf
					    ("ŒÌÐøÐÞžÄÆäËüÓÃ»§?(Y or N)\n");

					scanf("%c", &m);
					system("cls");

				} while (m == 'Y' || m == 'y');
				break;



			case 7:																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																	      /*****ÏÔÊŸ²åÈëÎ»ÖÃ×Ó²Ëµ¥*****/

				do {
					per = NEW;

					if (per == NULL)
					{	/* per ÎªNULL,ÐÂœáµã·ÖÅäÊ§°Ü */
						printf
						    ("Allocation failure\n");

						exit(1);

					}

					printf
					    ("\nÇëÊäÈëÐÂ»§Ö÷ÐÅÏ¢£º\n");

					printf("Inpute name:");

					getchar();

					gets(per->name);

					printf("Inpute address:");

					gets(per->address);

					printf("Inpute ID:");

					gets(per->ID);

					printf("Inpute date:");

					gets(per->date);

					printf("Inpute type:");

					gets(per->type);

					printf("Inpute fees:");

					gets(per->fees);

					printf("Inpute otherfees:");

					gets(per->otherfees);

					printf("Inpute remarks:");

					gets(per->remarks);

					per->next = NULL;

					system("cls");

					do {
						printf
						    ("****************²åÈëÎ»ÖÃ**************\n");

						printf
						    ("---------------------------------------\n");

						printf
						    (" 1£ºÔÚÖž¶š»§Ö÷ÐÕÃûÇ°      3£ºÔÚÖž¶šÈë×¡Ê±ŒäÇ°\n");

						printf
						    (" 2£ºÔÚÖž¶šµØÖ·Ç° \n");

						printf
						    ("---------------------------------------\n");

						printf
						    ("ÇëÄúÔÚÉÏÊö¹ŠÄÜÖÐÑ¡Ôñ(1-3):\n");

						scanf("%d", &c);

					} while (c < 1 || c > 3);
					system("cls");	/*ÔËÐÐÇ°ÇåÆÁ */



					switch (c)
					{
					case 1:
						printf
						    (" ÊäÈëÒª²åÈëÎ»ÖÃµÄÐÕÃû\n");

						scanf("%s", name);

						head =
						    insert1(head, per,
							    name);
						break;

					case 2:
						printf
						    (" ÊäÈëÒª²åÈëÎ»ÖÃµÄµØÖ·\n");

						scanf("%s", address);

						head =
						    insert2(head, per,
							    address);
						break;

					case 3:
						printf
						    (" ÊäÈëÒª²åÈëÎ»ÖÃµÄÈë×¡Ê±Œä\n");

						scanf("%s", date);

						head =
						    insert3(head, per,
							    date);
						break;

					}

					getchar();

					printf
					    ("ŒÌÐø²åÈëÆäËü»§Ö÷?(Y or N)\n");

					scanf("%c", &m);
					system("cls");	/*ÔËÐÐÇ°ÇåÆÁ */



				} while (m == 'Y' || m == 'y');
				break;





			case 8:
				save(head);
				break;

			}

			getchar();

			printf("·µ»ØÖ÷²Ëµ¥?(Y or N)\n");

			scanf("%c", &m);
			system("cls");	/*ÔËÐÐÇ°ÇåÆÁ */



		} while (m == 'Y' || m == 'y');



	}

	return 0;

}
