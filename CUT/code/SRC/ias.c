#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct product
{
    char product_name[20];
    int product_id;
    char product_description[100];
    int quantity;
    struct product *next ;
} product;

typedef struct sale
{
    int transaction_id;
    int time[3];
    int product_id;
    int quantity;
    
    struct date 
    {
    	int date[2];
    	char month[10];
    }date;
     struct sale *next ;
     
}sale;

product * file_to_list(product * , char *);

sale *file_to_list_sales(sale * , char *);

sale str_to_data_conversion_for_sales(char * ,sale ) ;

sale * create_linked_list_sale(sale * ,sale  ) ;

product *update_inventory_data(product * , int );

product * detele_info_inventory(product *, int ) ;

int save_data_into_file(product * , char *);

extern int intiger_validation(char *);
extern int alpha_validator(char *);

void display_sale();

void design()
{
	char a = '*' ;
	
	for(int i = 0 ; i < 30 ;i++)
		printf("%c",a);
	printf("\n");	
}





void display(product *start)
{

	if(start ==  NULL)
		printf("list is empty\n") ;
	
	product *p = start ;
	
	while(p!=NULL)
	{
		printf("product id :%d\n",p->product_id);
		printf("product name :%s\n",p->product_name);
		printf("product product_description:%s\n",p->product_description);
		printf("product quanity :%d\n",p->quantity);
		
		p = p->next ;
	}
}

int create(char *str)
{
    
    FILE *fp = fopen(str, "a+");
    
    int  product_id , quantity ,n ;
    char product_name[30] , product_description[30] , input[10];

    if(fp == NULL)
    {
        printf("Can't open file\n");  
        return 0; 
    }
    else
    {
    	printf("%s is opened successflly\n",str);
    }
    design();
    
    printf("\n how many records you what to enter\n");
        while(1)
        {
        	scanf("%s",input);
        	if(intiger_validation(input) != 0)
        	{
        		printf("please enter only numbers \n");
        	}
        	else 
        		break ;
        	
        }
        
     n = atoi(input);
   
    for (int i = 0; i < n; i++)
    {
        printf("\nnEnter product_id\n");
        while(1)
        {
        	scanf("%s", input);
        	if(intiger_validation(input) != 0)
        	{
        		printf("please enter only numbers \n");
        	}
        	else 
        		break ;
        }
        
        product_id = atoi(input);
        
        printf("\nnEnter product_name\n");
        
        while(1)
        {
        	scanf("%s", product_name);
        	if(alpha_validator(product_name))
        	{
        		break ;
        	}
        	else 
        	printf("please enter only characters\n");
	}        
        printf("\nEnter product_description\n");
        getchar();
        scanf("%[^\n]", product_description);
        
        printf("\nnEnter quantity\n");
        
	
	while(1)
	{
		scanf("%s", input);
        	if(intiger_validation(input) != 0)
        	{
        		printf("please enter only numbers \n");
        	}
        	else 
        		break ;
	}
        
        quantity = atoi(input);
        
        fprintf(fp,"%d,%s,%s,%d\n", product_id,
                product_name, product_description, quantity);

        printf("\nNew Account added to record\n");
        
        design();
    }

    fclose(fp);
}

void createsal(char *str)
{
    FILE *fp = fopen(str, "a+");

    int transaction_id, product_id, quantity, n;
    
    char input[10];

    if (fp == NULL)
    {
        printf("Can't open file\n") ;   
    }
    else
    	printf("%s is opened successflly\n",str);
    	
    design();
    printf("Entered sales Department\n");
    printf("\n how many records you what to enter\n");
    //scanf("%d", &n);
    
     while(1)
        {
        	scanf("%s",input);
        	if(intiger_validation(input) != 0)
        	{
        		printf("please enter only numbers \n");
        	}
        	else 
        		break ;
        	
        }
        
     n = atoi(input);
    
    for (int i = 0; i < n; i++)
    {
        printf("\nEnter transaction_id\n");
        //scanf("%d", &transaction_id);
        
        while(1)
	{
		scanf("%s", input);
        	if(intiger_validation(input) != 0)
        	{
        		printf("please enter only numbers \n");
        	}
        	else 
        		break ;
	}
        
        transaction_id =  atoi(input) ;
        
        printf("\nnEnter product_id\n");
        //scanf("%d", &product_id);
        
         while(1)
	{
		scanf("%s", input);
        	if(intiger_validation(input) != 0)
        	{
        		printf("please enter only numbers \n");
        	}
        	else 
        		break ;
	}
        
        product_id = atoi(input) ; 
        printf("\nnEnter quantity\n");
        //scanf("%d", &quantity);
        
         while(1)
	{
		scanf("%s", input);
        	if(intiger_validation(input) != 0)
        	{
        		printf("please enter only numbers \n");
        	}
        	else 
        		break ;
	}
	quantity = atoi(input) ; 
    
        fprintf(fp,"%d,%d,%s,%s,%d\n", product_id,
                transaction_id, __DATE__,__TIME__ , quantity);

        printf("\n New Account added to record to Sales \n");
        
        design();
    }

    fclose(fp);
}



int main()
{

	char *str = "Inventory.csv" ;
	char *sale_str = "sale.csv" ;
	product *source = NULL ;
	sale *source_sale = NULL ;
	int prod_id , exit_flag = 0 ;
	int ch ;
	design();
	printf("Welcome To Inventory Analysis Software \n") ;
	design();
	
	
	while(1)
	{
		 design();
		 printf("enter 1: create record\n");
        	 printf("enter 2: Display\n");
        	 printf("enter 3: Update\n");
        	 printf("enter 4: Delete\n");
        	 printf("enter 5: exit\n");
        	 
        	 design();
        	 printf("enter your choice: \n");
        	 scanf("%d", &ch);
        	 
		 
		switch (ch)
		{
			case 1:
		    		create(str);
		    		createsal(sale_str) ;
		    	
		    		source = file_to_list(source ,str);
		    		source_sale = file_to_list_sales(source_sale,sale_str);
		   	 	break;
			
			case 2:
				if(source == NULL)
				{
					source = file_to_list(source ,str);
				 	source_sale = file_to_list_sales(source_sale,sale_str);
				}
				
				design();
				display(source);
				design();
				display_sale(source_sale);
				design();
				break ;
			case 3:
				printf("enter the product id \n");
				scanf("%d",&prod_id);  
				source = update_inventory_data(source ,prod_id );
				save_data_into_file(source , str);
				break ;
			case 4:
				printf("enter the product id \n");
				scanf("%d",&prod_id);
				source = detele_info_inventory(source , prod_id) ;
		 		save_data_into_file(source , str);
		 		break ;
		 	case 5: 
		 		exit_flag = 1;
				
		}
		
		if(exit_flag == 1)
		{
			 design();
			 printf("THANK YOU\n");
			 design();
			 break;
		}
			
	}	
}

product * create_linked_list(product *source ,product data )
{
	
		int i = 0;					

	
			
		if(source == NULL)	
		{
			source  = (product *)malloc(sizeof(product));
			
			source->product_id = data.product_id ;
			source->quantity = data.quantity ;
			strcpy(source->product_name , data.product_name) ;
			strcpy(source->product_description , data.product_description) ;
			source->next =	 NULL;
		}
		else 
		{
		
			
			
			product *p = source ;	
			product *temp = (product *) malloc(sizeof(product));
		
			 while(p->next != NULL)
			 {
			 	p = p->next ;
				
				 	
			 }
			 
			temp->product_id = data.product_id ;
			temp->quantity = data.quantity ;
			strcpy(temp->product_name , data.product_name) ;
			strcpy(temp->product_description , data.product_description) ;
			 
			p->next = temp ;
			temp->next = NULL ;
	
			
		}
		
		return source ;

}


product str_to_data_conversion(char *str ,product updated_data )
{
	
	int i = 0, j =0 , flag = 0;
	char temp[10] , count =0 ;
	
	while(str[i] != '\0')
	{
		if(str[i] !=',')
		{	
			
			   temp[j++] = str[i++];
			   temp[j] = '\0';
		}
		else 
		{
			i++ ;
			j=0;
			
			//printf("temp %s",temp);
			
			if(temp[0] >= 'a' && temp[0] <= 'z')
			{
				
				if(count == 0)
				{
					//printf("product name %s \n", temp);
					strcpy(updated_data.product_name , temp) ;
					count = 1;
				}
				else 
				{
					flag = 1;
					strcpy(updated_data.product_description , temp) ;	
					//printf("product discrpition %s\n",updated_data.product_description);
					//getchar();
				}
			}
			else 
			{
				//printf("product_id temp :%s\n",temp);
				updated_data.product_id = atoi(temp);
			}
		}
		if(flag == 1)
		{
			//printf("quantity temp :%s\n",temp);
			updated_data.quantity = atoi(temp);
			//printf("quantity temp int :%d\n",updated_data.quantity);
		}
	}
	
	//printf("test\n");
return updated_data ;

}
product * file_to_list(product *source , char *str)
{
    
    
    FILE *ptr = NULL , *stream = NULL ;
    
    char buffer[40];
    
    int product_id ;
    
    product updated_data ; 
    
    /*stream = fopen(str, "w");
    if(stream == NULL)
    {
    	printf("file creation is failed \n");
    }*/
    
    if(source == NULL)
    {
    	//printf("list is empty \n");
    	//return NULL ;
    }
    ptr = fopen(str,"r");
    
    
    if(ptr == NULL)
    {
    	printf("file is not found \n");
    	return NULL ;
    }
    else 
    {
    	//printf("file reading is done\n");
    	
    	
    	while(!feof(ptr))
	{
		if(!(fgets(buffer,40,ptr)))
		{
			//printf("string reading is fail\n");
			break ;
		}
		else 
		{
			//printf("output : %s\n",buffer);
			
		
			updated_data = str_to_data_conversion(buffer , updated_data);
			
			/*printf("product id :%d\n",updated_data.product_id);
			printf("product name :%s\n",updated_data.product_name);
			printf("product id :%s\n",updated_data.product_description);
			printf("product name :%d\n",updated_data.quantity);
			
			/*
			fprintf(stream, "%d,%s,%s,%d\n", updated_data.product_id, updated_data.product_name , updated_data.product_description , updated_data.quantity);
			*/
			
			source = create_linked_list(source ,updated_data );
		}
	}		
    }
    
    fclose(ptr);
  //  fclose(stream);
    
    return source ;
}

	


sale *file_to_list_sales(sale *source_sale, char *str)
{
	FILE *ptr = NULL , *stream = NULL ;
    
    	char buffer[40];
    
    	int product_id ;
    
    	sale updated_data ; 
    	
    	 if(source_sale == NULL)
    	{
	    	//printf("list is empty \n");
	    	//return NULL ;
	}
   
   	 ptr = fopen(str,"r"); 
	    if(ptr == NULL)
	    {
	    	printf("file is not found \n");
	    	return NULL;
	    }
	    else 
	    {
	    	//printf("file reading is done\n");
	    	
	    	
	    	while(!feof(ptr))
		{
			if(!(fgets(buffer,40,ptr)))
			{
				//printf("string reading is fail\n");
				break ;
			}
			else 
			{
				//printf("output : %s\n",buffer);
				updated_data = str_to_data_conversion_for_sales(buffer ,updated_data );
				
				source_sale = create_linked_list_sale(source_sale , updated_data);
				
				
				
			}
		}
	}
	
return source_sale ;
}	

sale str_to_data_conversion_for_sales(char *str ,sale updated_data )
{
	
	int i = 0, j =0 , k = 0, l = 0 , index =0 , flag = 0 , count =0 , date_flag = 0;
	char temp[10]  , time[5] ;
	char date[10];
	
	while(str[i] != '\0')
	{
		if(str[i] !=',')
		{	
				
			   temp[j++] = str[i++];
			   temp[j] = '\0';
			   
			   //printf("temp %s \n",temp);
			   
		}
		else 
		{
			i++ ;
			j=0;
			
			if(count == 0)
			{
				updated_data.transaction_id = atoi(temp);
				//printf("transction id is %d \n",updated_data.transaction_id);
				
				count = 1;
			}
			else if(count == 1)
			{
				updated_data.product_id = atoi(temp); 
				//printf("product_id id is %d \n",updated_data.product_id);
				count = 2; 
			}		
			else if(count == 2)
			{
				l = 0 ;
				k= 0 ;
				while(temp[l] !='\0')
				{
					if(temp[l] !=' ')
					{
						time[k++] = temp[l++];	
						time[k] = '\0';
					}
					else
					{
						
						k=0;
						l++ ;
						if(date_flag == 0)
						{
							//printf("test %s\n",time);
							strcpy(updated_data.date.month , time);
							date_flag = 1;
						}
						else if(date_flag == 1)
						{
							//printf("test %s\n",time);
							
							updated_data.date.date[0] = atoi(time);
						}
					}
					
				}
				//printf("test %s\n",time);
				updated_data.date.date[1] = atoi(temp); 
				count = 3; 
			}	
			else if(count == 3)
			{
				l = 0 , k = 0 , index = 0;
				
				//printf("time temp : %s \n", temp);
				
				while(temp[l] != '\0')
				{
					if(temp[l] != ':')
					{
						date[k++] = temp[l++];
					}
					else
					{
						k = 0;
						l++;
						updated_data.time[index++] = atoi(date);
						//printf("update time int format is %d \n",updated_data.time[index++]);
						
					}
				}
				updated_data.time[index] = atoi(time); 
				
				count = 6;
			}
			
		}
	}
	updated_data.quantity = atoi(temp) ;	
return updated_data ;
}

sale * create_linked_list_sale(sale *source ,sale data )
{
	
		int i = 0;					

		if(source == NULL)	
		{
			source  = (sale *)malloc(sizeof(sale));
			
			source->transaction_id = data.transaction_id ;
			source->time[0] = data.time[0];
			source->time[1] = data.time[1];
			source->time[2] = data.time[2];
			source->product_id = data.product_id ;
			source->quantity = data.quantity ;
			source->date.date[0] = data.date.date[0] ;
			source->date.date[1] = data.date.date[1] ;
			
			strcpy(source->date.month , data.date.month) ;
			
			source->next =	 NULL;
		}
		else 
		{
			sale *p = source ;	
			sale *temp = (sale *) malloc(sizeof(sale));
		
			 while(p->next != NULL)
			 {
			 	p = p->next ;
				
				 	
			 }
			 
			temp->transaction_id = data.transaction_id ;
			temp->time[0] = data.time[0];
			temp->time[1] = data.time[1];
			temp->time[2] = data.time[2];
			temp->product_id = data.product_id ;
			temp->quantity = data.quantity ;
			temp->date.date[0] = data.date.date[0] ;
			temp->date.date[1] = data.date.date[1] ;
			
			strcpy(temp->date.month , data.date.month) ;
			 
			p->next = temp ;
			temp->next = NULL ;
	
			
		}
		
		return source ;

}


void display_sale(sale *start)
{

	if(start ==  NULL)
	{
		printf("list is empty\n") ;
	}
	else
	{
	
		printf("Sale Data\n");
		sale *p = start ;
		
		while(p!=NULL)
		{
			printf("transction id is %d \n",p->transaction_id);
			printf("product_id id is %d \n",p->product_id);
			printf("Date %s %d %d \n",p->date.month ,p->date.date[0] , p->date.date[1] );
			printf("Time %d:%d:%d \n",p->time[0] , p->time[1] ,p->time[2]) ;
			printf("Quanity is %d\n",p->quantity);
			
			p = p->next ;
		}
	}
}


product *update_inventory_data(product *source , int id )
{
	product *p = source ;
	int flag = 0 ;
	char ch ;
	while(p!=NULL)
	{
		if(p->product_id  == id)
		{
			flag = 1;
			printf("product name :%s\n",p->product_name);
			printf("product product_description :%s\n",p->product_description);
			printf("product quantiy  :%d\n",p->quantity);
			
			design();
			printf("enter Y to change the details or N  to skip \n");
			scanf(" %c",&ch);
			if(ch == 'y' || ch == 'Y')
			{
				printf("enter the product name\n");
				scanf("%s",p->product_name) ;
				
				printf("enter product description \n");
				getchar();
        			scanf("%[^\n]", p->product_description);
				
				printf("enter the quantity \n");
				scanf("%d",&p->quantity) ;
				
			}
			else 
			{
				break;
			}
			
		}
		p = p->next ;
	}
	
	if(flag == 1)
		return source ;
	else 
		return NULL;
}


int save_data_into_file(product *source  , char *str)
{
	
	FILE *fptr = NULL; 
	
	fptr = fopen(str,"w");

	if(fptr == NULL)
	{
		printf("%s is not opened \n",str);
		return 0 ;
	}
	else 
	{
		
		if(source ==  NULL)
		{
			printf("list is empty\n") ;
			return -1;
		}
		
		product *p = source ;
		
		while(p!=NULL)
		{
			fprintf(fptr,"%d,%s,%s,%d\n", p->product_id, p->product_name , p->product_description , p->quantity);
			
			p = p->next ;
		}
	}
	
	fclose(fptr);
}
int *lookup(product *source, int prod_id , int *index )
{
	
	
	 int count = 1 , check_flag = 0;
	 
	 if(source ==  NULL)
	 {
		printf("list is empty\n") ;
		return NULL ;
	  }
	
	product *p = source ;
	
	int i = 0 , j =0;
	
	while(p!=NULL)
	{
		if(p->product_id  == prod_id)
		{
			printf("product name :%s\n",p->product_name);
			printf("product product_description :%s\n",p->product_description);
			printf("product quantiy  :%d\n",p->quantity);
			
			check_flag = 1;
		}
		else 
		{
			count++;	
		}
		p = p->next ;
	}
	
	if(check_flag == 1)
		*index = count ;
	else
		*index = -1;
	
	return index ;
}
int* len_of_list(product  *source ,int *index)
{
	int count =0 ;
	
	if(source ==  NULL)
	{
		printf("list is empty\n") ;
		return NULL ;
	}
	
	
	product   *p = source ;
	
	while(p!=NULL)
	{
		count ++;	
		p = p->next ;
	}
	
	*index = count ;
	
	return index ;	
}
product * detele_info_inventory(product *source  , int prod_id)
{
	int position = 0   , len = 0 , link =1;
	
	char ch ;
	
	if(source ==  NULL)
	{
		printf("list is empty\n") ;
		return NULL ;
	 }
	 
	 
	product *p = source ;
	product *temp = source  ;
	
	position = *lookup(p,prod_id,&position) ; 
	len = *len_of_list(p,&len);
	
	printf("please enter y to delete \n");
	scanf(" %c",&ch);
	
	if((ch == 'y' || ch == 'Y')&&position >0)
	{
		if(position == 1)
		{
			source = temp->next ;
			temp->next = NULL ;
		}
		else if(position < len)
		{
				 
			while(link < position-1)
			{
				temp = temp->next;
				link++ ;
					
			}
			
			product* del = temp->next;
			del->next = del->next ;
			temp->next = del->next ;		
			
		}
		else if(position == len)
		{
			link = 1 ;
			printf("second\n");    
			
			while(link < position-1)
			{
				temp = temp->next; 
				link++;
			}
			
			temp->next = NULL;
			
		
		}
	}
	else 
	printf("ip address is not deleted\n");	
	return source;	
}
