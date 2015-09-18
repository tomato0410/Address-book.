#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct address
{
	 char name[20];
	 char corp[30];
	 char phone[20];
	 struct address *prev;
	 struct address *next;
}ADDRESS;

void save_addresses(void);
void load_addresses(void);
void register_address(void);
void delete_address(void);
void search_address(void);
void print_all_address(void);

ADDRESS *head = NULL, *tail = NULL;

int main(void)
{
	int n; 
	while(1)
	{
		printf("\n<<<<<<<<<<<\n1:Add Adress, \n2:Delete Address, \n3:Search Address, \n4:Print All Addresses, \n5:Save All Addresses, \n6:Load All Addresses, \n0:Exit\n >>>>>>>>>>>\n");
		printf("Select. : ");
		scanf_s("%d", &n);    fflush(stdin); 

		if(n == 1) register_address();
		else if(n == 2) delete_address();
		else if(n == 3) search_address();
		else if(n == 4) print_all_address();
		else if(n == 5) save_addresses();
		else if(n == 6) load_addresses();
		else if(n == 0)                 
		{
			printf("\n<Exit Address Book.>\n");
			break;
		}
		else printf("\nSelect in Menu.\n");
	}
}

void register_address(void)
{
	ADDRESS *pnode = (ADDRESS*)malloc(sizeof(ADDRESS));

	printf("\nName : ");		gets_s(pnode->name); 
	printf("Corporation : ");	gets_s(pnode->corp);
	printf("Phone : ");			gets_s(pnode->phone);  
    
	if(head == NULL)
    {
        pnode->next = NULL;  
        pnode->prev = NULL;   
        head = tail = pnode; 
    }
    else
    {
        pnode->next = NULL;   
        pnode->prev = tail;   
        tail->next = pnode;   
        tail = pnode;       
    }
	printf("\n<Address was added.>\n");
}


void save_addresses(void)
{
	FILE *fp;
	errno_t err;
	ADDRESS *pnode = head;

	if(head == NULL) printf("\n<There are no addresses in List.>\n");
	else
	{
		printf("\n<Save all addrsses.>\n");
		if(err = fopen_s(&fp, "address_output.txt", "w") != 0)
		{
			printf("File open was failed.\n");
			exit(1);
		}
		else
		{
			while(pnode)
			{
				if(pnode == tail)
				{
					fprintf_s(fp, "%s %s %s", pnode->name, pnode->corp, pnode->phone);
				}
				else
				{
					fprintf_s(fp, "%s %s %s\n", pnode->name, pnode->corp, pnode->phone);
				}
				pnode = pnode->next;
			}
			fclose(fp);
		}
	}
}


void load_addresses(void)
{
	FILE *fp;
	errno_t err;
	ADDRESS *pnode;

	printf("\n<Load all addrsses.>\n");

	if(err = fopen_s(&fp, "address_output.txt", "r") != 0)
	{
		printf("File open was failed.\n");
		exit(1);
	}
	else
	{
		while(feof(fp) == 0)
		{
			pnode = (ADDRESS*)malloc(sizeof(ADDRESS));
			fscanf_s(fp, "%s ", pnode->name, sizeof(pnode->name));
			fscanf_s(fp, "%s ", pnode->corp, sizeof(pnode->corp));
			fscanf_s(fp, "%s", pnode->phone, sizeof(pnode->phone));

			if(head == NULL)
			{
				pnode->next = NULL;
				pnode->prev = NULL;
				head = tail = pnode;
			}
			else
			{
				pnode->next = NULL;
				pnode->prev = tail; 
				tail->next = pnode; 
				tail = pnode;
			}
		}
		fclose(fp);
	}
}


void delete_address(void)
{
	char name[10];
	ADDRESS *pnode = head, *pn;

	if(head == NULL) printf("\n<There are no addresses in List.>\n");
	else
	{
		printf("\nInput name you want to delete. : "); gets_s(name); 
		while(pnode)
		{
			if(strcmp(pnode->name, name) == 0)
			{
				if( pnode == head )
				{
					if(head->next == NULL)
					{
						head = NULL; tail = NULL;  
					}
					else
					{
						head = head->next;  
						head->prev = NULL;
					}
				}
				else if( pnode == tail )
				{
					tail = pnode->prev;  
					tail->next = NULL;
				}
				else
				{
					pn = pnode->next;  
					pn->prev = pnode->prev;  
					pn = pnode->prev;  
					pn->next = pnode->next;  
				}
				free(pnode);
				pnode = NULL;
				printf("\n<Address was deleted.>\n"); 
				break;
			}
			else pnode = pnode->next;
		}
		if(pnode == NULL) printf("\n<There is no address you want to delete.>\n");
	}
}

		
void search_address(void)
{
	char name[20];
	ADDRESS *pnode = head;
	if(head == NULL) printf("\n<There are no addresses in List.>\n");
	else
	{
		printf("\nInput name you want to find. : "); gets_s(name);
		
		while(pnode)
		{
			if(strcmp(pnode->name, name)==0)
			{
				printf("\n------------------------------------------------\n");
				printf("%s\t\t", pnode->name);
				printf("%s\t\t", pnode->corp);
				printf("%s\t\t", pnode->phone);
				printf("\n------------------------------------------------\n");
				break;
			}
			else pnode = pnode->next;
		}
		if(pnode == NULL) printf("\n<There is no address you want to find.>\n");
	}
}

void print_all_address(void)
{
	ADDRESS *pnode = head;

	if(head == NULL) printf("\n<There are no addresses in List.>\n");
	else
	{
		printf("\n<Print all addrsses.>\n");
		printf("\n------------------------------------------------\n");
		while(pnode)
		{
			printf("%s\t\t", pnode->name);
			printf("%s\t\t", pnode->corp);
			printf("%s\t\t", pnode->phone);
			printf("\n------------------------------------------------\n");
			pnode = pnode->next;
		}
	}
}