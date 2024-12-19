#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Book
{
    int id;
    char bookName[20];
    char authorName[20];
    char catagory[20];
    int price;
    float rating;
}Book;
//declaration
void hc(Book*);
Book* creatArray(int);//calloc
void add(Book*);
void allBook(Book*);
int search(Book*);
void delet(Book*);
void update(Book*);
void catagory(Book*);
void sort(Book*);
//global intialization
int count=10;
int size=50;
//
void main()
{
    Book* arr=creatArray(size);
    hc(arr);
    
    int choice,res;
    do{
        printf("\n\n**************************");
        printf("\n1.Add Book\n2.Display All Books\n3.Search Book\n4.Remove Book\n5.Update Book Data\n6.Show Category's Books\n7.Display Sorted Books\n");
        printf("**************************");
        printf("\nEnter Your Choice : "); 
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            add(arr);
            break;
        case 2:
            allBook(arr);
            break;
        case 3:
            res=search(arr);
            break;
        case 4:
            delet(arr);
            break;
        case 5:
            update(arr);
            break;
        case 6:
            catagory(arr);
            break;
        case 7:
            sort(arr);
            break;
        default:
            printf("\n\nEnter Correct Choice!\n\n");
        }
    }while(choice!=0);
}
Book* creatArray(int size)
{
    Book* arr =(Book*)calloc(size,sizeof(Book));
    return arr;
}
void add(Book* arr)
{
    for(int i=count;i<=count;i++){
        printf("\n\nEnter Book ID : ");
        scanf("%d",&arr[i].id);
        printf("Enter Book name : ");
        fflush(stdin);
        gets(arr[i].bookName);
        printf("Enter Author name : ");
        fflush(stdin);
        gets(arr[i].authorName);
        printf("Enter Book Catagory : ");
        fflush(stdin);
        gets(arr[i].catagory);
        printf("Enter Book price : ");
        scanf("%d",&arr[i].price);
        printf("Enter Book Rating '0' to '10' : ");
        scanf("%f",&arr[i].rating);
        while(arr[i].rating>=10){
            if (arr[i].rating>=10){
                printf("!!Give rating under '10' :");
                scanf("%f",&arr[i].rating);
            }
        }
        printf("\n");
    }
    count++;
}
void allBook(Book* arr)
{
    printf("\n--------------------------------------------------------------------------------------------------------");
    printf("\n|   Book id   |   Book name   |   Author name   |   Book catagory   |   Book price   |   Book rating   |");
    printf("\n--------------------------------------------------------------------------------------------------------");
    for(int i=0;i<count;i++){
        printf("\n|     %-5d   |       %-5s   |        %-6s   |      %-10s   |     %-8d   |       %-7.1f   |",arr[i].id,arr[i].bookName,arr[i].authorName,arr[i].catagory,arr[i].price,arr[i].rating);
        printf("\n--------------------------------------------------------------------------------------------------------");    
        }
}
int search(Book* arr)
{
    int choice,bid,i,cnt=0;
    char bname[20];
    printf("\n1.Search by id\n2.Search by book name");
    printf("\n\nEnter Choice :");
    scanf("%d",&choice);
    if(choice==1){
        printf("\nEnter Book id : ");
        scanf("%d",&bid);
        printf("\n--------------------------------------------------------------------------------------------------------");
        printf("\n|   Book id   |   Book name   |   Author name   |   Book catagory   |   Book price   |   Book rating   |");
        printf("\n--------------------------------------------------------------------------------------------------------");
        for(i=0;i<=count;i++){
            if(arr[i].id==bid){
                printf("\n|     %-5d   |       %-5s   |        %-6s   |      %-10s   |     %-8d   |       %-7.1f   |",arr[i].id,arr[i].bookName,arr[i].authorName,arr[i].catagory,arr[i].price,arr[i].rating);
                printf("\n--------------------------------------------------------------------------------------------------------");
                cnt++;
                return i;
            }
        }
        if (cnt==0){
            printf("\nBook not found!\n");  
            return -1;        
        }
    }
    else if (choice==2){
        printf("\nEnter Book name : ");
        scanf("%s",bname);
        printf("\n--------------------------------------------------------------------------------------------------------");
        printf("\n|   Book id   |   Book name   |   Author name   |   Book catagory   |   Book price   |   Book rating   |");
        printf("\n--------------------------------------------------------------------------------------------------------");
        for(i=0;i<=count;i++){
            int res = strcasecmp(arr[i].bookName,bname);
            if(res==0){
                printf("\n|     %-5d   |       %-5s   |        %-6s   |      %-10s   |     %-8d   |       %-7.1f   |",arr[i].id,arr[i].bookName,arr[i].authorName,arr[i].catagory,arr[i].price,arr[i].rating);
                printf("\n--------------------------------------------------------------------------------------------------------");
                cnt++;
                return i;
            }
        }
        if (cnt==0){
            printf("\nBook not found!\n");
            return -1;
        }   
    }
    else{
        printf("Enter Correct choice");
    }
}
void delet(Book* arr)
{
    printf("\nSearch Book you want to delete :");
    int res =search(arr);
    if(res != -1){
        for (int i = res; i < count-1; i++){
            arr[i]=arr[i+1];  
        }
        printf("\nRecord deleted!\n");
        printf("~~~~~~~~~~~~~~~~~~~");
        count--;
    }
}
void update(Book* arr)
{
    int choice;
    printf("\nSearch Book you want to update :");
    int res =search(arr);
    if(res != -1){
    printf("\n1.Update price\n2.Update rating");
    printf("\n\nEnter Choice :");
    scanf("%d",&choice);
    if (choice==1){
        printf("Enter updated price : ");
        scanf("%d",&arr[res].price);
        printf("\nRecord updated!");
        printf("\n^^^^^^^^^^^^^^^^^^^\n");
    }
    else if (choice==2){
        printf("\nEnter updated rating : ");
        scanf("%f",&arr[res].rating);
        while(arr[res].rating>=10){
            if (arr[res].rating>=10){
                printf("!!Give rating under '10' :");
                scanf("%f",&arr[res].rating);
            }
        printf("\nRecord updated!");
        printf("\n^^^^^^^^^^^^^^^^^^^\n");
        }
    }
    else{
        printf("\nEnter Correct choice!!");
    } 
    }
}
void catagory(Book* arr)
{
    int cnt=0,i;
    char cat[20];
    printf("\n\nEnter catagory :");
    scanf("%s",cat);
    printf("\n--------------------------------------------------------------------------------------------------------");
    printf("\n|   Book id   |   Book name   |   Author name   |   Book catagory   |   Book price   |   Book rating   |");
    printf("\n--------------------------------------------------------------------------------------------------------");
        for(i=0;i<=count;i++){
            int a=strcasecmp(arr[i].catagory,cat);
            if(a==0){
                cnt++;
                printf("\n|     %-5d   |       %-5s   |        %-6s   |      %-10s   |     %-8d   |       %-7.1f   |",arr[i].id,arr[i].bookName,arr[i].authorName,arr[i].catagory,arr[i].price,arr[i].rating);
                printf("\n--------------------------------------------------------------------------------------------------------");
            }
        }
        if (cnt==0){
            printf("Catagory not found!!");
        }     
}
void sort(Book* arr)
{
    int choice,choice1;
    Book arr1[size];
    for(int i=0;i<count;i++){
        arr1[i].id=arr[i].id;
        strcpy(arr1[i].bookName,arr[i].bookName);
        strcpy(arr1[i].authorName,arr[i].authorName);;
        strcpy(arr1[i].catagory,arr[i].catagory);
        arr1[i].price=arr[i].price;
        arr1[i].rating=arr[i].rating;
    }
    Book temp[size];
    printf("\n1.Sort by price\n2.sort by rating");
    printf("\n\nEnter Choice :");
    scanf("%d",&choice);
    if (choice==1){
        printf("\n1.Asending order\n2.Desending order");
        printf("\n\nEnter Choice :");
        scanf("%d",&choice1);
        if (choice1==1){
            printf("\n--------------------------------------------------------------------------------------------------------");
            printf("\n|   Book id   |   Book name   |   Author name   |   Book catagory   |   Book price   |   Book rating   |");
            printf("\n--------------------------------------------------------------------------------------------------------");
            for(int i=0;i<count;i++){
                for(int j=i+1;j<count;j++){
                    if(arr1[i].price > arr1[j].price){
                        temp[0]= arr1[i];
                        arr1[i] = arr1[j];
                        arr1[j] = temp[0];
                    }
                }
                printf("\n|     %-5d   |       %-5s   |        %-6s   |      %-10s   |     %-8d   |       %-7.1f   |",arr1[i].id,arr1[i].bookName,arr1[i].authorName,arr1[i].catagory,arr1[i].price,arr1[i].rating);
                printf("\n--------------------------------------------------------------------------------------------------------");
            }
        }
        else if (choice1==2){
            printf("\n--------------------------------------------------------------------------------------------------------");
            printf("\n|   Book id   |   Book name   |   Author name   |   Book catagory   |   Book price   |   Book rating   |");
            printf("\n--------------------------------------------------------------------------------------------------------");
            for(int i=0;i<count;i++){
                for(int j=i+1;j<count;j++){
                    if(arr1[i].price < arr1[j].price){
                        temp[0]= arr1[i];
                        arr1[i] = arr1[j];
                        arr1[j] = temp[0];
                    }
                }
                printf("\n|     %-5d   |       %-5s   |        %-6s   |      %-10s   |     %-8d   |       %-7.1f   |",arr1[i].id,arr1[i].bookName,arr1[i].authorName,arr1[i].catagory,arr1[i].price,arr1[i].rating);
                printf("\n--------------------------------------------------------------------------------------------------------");
            }
        }
        else{
        printf("\nEnter Correct choice!!");
        }
    }
    else if (choice==2){
        printf("\n1.Asending order\n2.Desending order");
        printf("\n\nEnter Choice :");
        scanf("%d",&choice1);
        if (choice1==1){
            printf("\n--------------------------------------------------------------------------------------------------------");
            printf("\n|   Book id   |   Book name   |   Author name   |   Book catagory   |   Book price   |   Book rating   |");
            printf("\n--------------------------------------------------------------------------------------------------------");
            for(int i=0;i<count;i++){
                for(int j=i+1;j<count;j++){
                    if(arr1[i].rating > arr1[j].rating){
                        temp[0] = arr1[i];
                        arr1[i] = arr1[j];
                        arr1[j] = temp[0];
                    }
                }
                printf("\n|     %-5d   |       %-5s   |        %-6s   |      %-10s   |     %-8d   |       %-7.1f   |",arr1[i].id,arr1[i].bookName,arr1[i].authorName,arr1[i].catagory,arr1[i].price,arr1[i].rating);
                printf("\n--------------------------------------------------------------------------------------------------------");
            }
        }
        else if (choice1==2){
            printf("\n--------------------------------------------------------------------------------------------------------");
            printf("\n|   Book id   |   Book name   |   Author name   |   Book catagory   |   Book price   |   Book rating   |");
            printf("\n--------------------------------------------------------------------------------------------------------");
            for(int i=0;i<count;i++){
                for(int j=i+1;j<count;j++){
                    if(arr1[i].rating < arr1[j].rating){
                        temp[0] = arr1[i];
                        arr1[i] = arr1[j];
                        arr1[j] = temp[0];
                    }
                }
                printf("\n|     %-5d   |       %-5s   |        %-6s   |      %-10s   |     %-8d   |       %-7.1f   |",arr1[i].id,arr1[i].bookName,arr1[i].authorName,arr1[i].catagory,arr1[i].price,arr1[i].rating);
                printf("\n--------------------------------------------------------------------------------------------------------");
            }
        }   
    }
    else{
        printf("\nEnter Correct choice!!");
    } 
}
void hc(Book* arr)
{
    arr[0].id=1;
    strcpy(arr[0].bookName,"a");
    strcpy(arr[0].authorName,"b");
    strcpy(arr[0].catagory,"crime");
    arr[0].price=150;
    arr[0].rating=7.8;
    //
    arr[1].id=2;
    strcpy(arr[1].bookName,"c");
    strcpy(arr[1].authorName,"d");
    strcpy(arr[1].catagory,"crime");
    arr[1].price=300;
    arr[1].rating=9.4;
    //
    arr[2].id=3;
    strcpy(arr[2].bookName,"e");
    strcpy(arr[2].authorName,"f");
    strcpy(arr[2].catagory,"crime");
    arr[2].price=500;
    arr[2].rating=7.5;
    //
    arr[3].id=4;
    strcpy(arr[3].bookName,"g");
    strcpy(arr[3].authorName,"h");
    strcpy(arr[3].catagory,"comedy");
    arr[3].price=280;
    arr[3].rating=8.8;
    //
    arr[4].id=5;
    strcpy(arr[4].bookName,"i");
    strcpy(arr[4].authorName,"j");
    strcpy(arr[4].catagory,"comedy");
    arr[4].price=99;
    arr[4].rating=9;
    //
    arr[5].id=6;
    strcpy(arr[5].bookName,"k");
    strcpy(arr[5].authorName,"l");
    strcpy(arr[5].catagory,"comedy");
    arr[5].price=799;
    arr[5].rating=6.7;
    //
    arr[6].id=7;
    strcpy(arr[6].bookName,"m");
    strcpy(arr[6].authorName,"n");
    strcpy(arr[6].catagory,"suspense");
    arr[6].price=650;
    arr[6].rating=6.9;
    //
    arr[7].id=8;
    strcpy(arr[7].bookName,"o");
    strcpy(arr[7].authorName,"p");
    strcpy(arr[7].catagory,"suspense");
    arr[7].price=720;
    arr[7].rating=7;
    //
    arr[8].id=9;
    strcpy(arr[8].bookName,"q");
    strcpy(arr[8].authorName,"r");
    strcpy(arr[8].catagory,"suspense");
    arr[8].price=190;
    arr[8].rating=7.1;
    //
    arr[9].id=10;
    strcpy(arr[9].bookName,"s");
    strcpy(arr[9].authorName,"t");
    strcpy(arr[9].catagory,"comedy");
    arr[9].price=350;
    arr[9].rating=9.8;
}