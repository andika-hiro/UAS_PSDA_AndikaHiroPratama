#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <iostream>

typedef struct Node
{
    int data;
    Node *kiri;
    Node *kanan;
};

Node *tree = NULL;

using namespace std;

void insert (Node **root, int databaru)
{
    if ((*root)==NULL)
       {
        Node *baru;
        baru = new Node;
        baru->data=databaru;
        baru->kiri=NULL;
        baru->kanan=NULL;
        (*root) = baru;
        (*root) -> kiri = NULL;
        (*root) -> kanan = NULL;
        printf("Data Dimasukkan Ke Dalam Node");
       }
    else if (databaru<(*root)->data)
              insert(&(*root)->kiri,databaru);
    else if (databaru>(*root)->data)
        insert(&(*root)->kanan,databaru);
    else if (databaru==(*root)->data)
        printf("===== Error : Data Sudah Ada Dalam Node =====");
}

void preOrder(Node *root)
{
    if(root!=NULL)
    {
        if(root->data!=NULL)
        {
            printf("%d ",root->data);
        }
        preOrder(root->kiri);
        preOrder(root->kanan);
    }
}

void inOrder(Node *root)
{
       if(root!=NULL)
       {
           inOrder(root->kiri);
           if(root->data!=NULL)
           {
               printf("%d ",root->data);
           }
           inOrder(root->kanan);
        }
}

void postOrder(Node *root)
{
       if(root!=NULL)
       {
         postOrder(root->kiri);
         postOrder(root->kanan);
         if(root->data!=NULL)
         {
            printf("%d ",root->data);
         }
       }
}

int count(Node *root)
{
       if(root==NULL)
              return 0;
       else
              return count(root->kiri)+ count(root->kanan)+1;
}
int height(Node *root)
{
       if(root == NULL)
              return -1;
       else{
              int u = height(root->kiri);
        int v = height(root->kanan);
        if(u > v)
          return u + 1;
        else
          return v + 1;
       }
}

void search(Node **root, int cari)
{
    if((*root) == NULL)
    {
        printf("TIDAK DITEMUKAN");
    }
    else if(cari < (*root)->data)
        search(&(*root)->kiri,cari);
    else if(cari > (*root)->data)
        search(&(*root)->kanan,cari);
    else if(cari == (*root)->data)
        printf("\n===== DITEMUKAN ===== \n");
        printf("\nData Ter Scan: %d ", (*root)->data);
}

int Max(struct Node* root) 
{ 
    if (root == NULL) 
      return INT_MIN; 
    int res = root->data; 
    int lres = Max(root->kiri); 
    int rres = Max(root->kanan); 
    if (lres > res) 
      res = lres; 
    if (rres > res) 
      res = rres; 
    return res; 
} 

int Min(struct Node* root) 
{ 
    if (root == NULL) 
      return INT_MAX; 
    int res = root->data; 
    int lres = Min(root->kiri); 
    int rres = Min(root->kanan); 
    if (lres < res) 
      res = lres; 
    if (rres < res) 
      res = rres; 
    return res; 
} 

void hapus(Node **root, int del)
{
       Node *curr;
       Node *parent;
       curr = (*root);

       bool flag = false;
  
       while(curr != NULL)
       {
              if(curr->data == del)
              {
                     flag = true;
                     //cout<<"Data ditemukan!";
                      break;
              }
              else
              {
                  parent = curr;
                  if(del>curr->data)
                     curr = curr->kanan;
                  else
                     curr = curr->kiri;
              }
       }

    if(!flag)
    {
        cout<<"===== ERROR : Data Tidak Ada Dalam Node =====."<<endl;
        return;
    }
    
       if(height(tree) == 0)
       {
              if( curr->kiri== NULL && curr->kanan == NULL)
              {
                     (*root) = NULL;
                    
                     return;
              }
       }

       else if(height(tree) > 0)
       {
              if( curr->kiri== NULL && curr->kanan == NULL)
              {
                     if(parent->kiri == curr)
                     {
                           parent->kiri = NULL;
                           delete curr;
                     }
                     else
                     {
                           parent->kanan = NULL;
                           delete curr;
                     }

                     return;
              }

              if((curr->kiri == NULL && curr->kanan != NULL)|| (curr->kiri != NULL && curr->kanan == NULL))
              {
                     if(curr->kiri == NULL && curr->kanan != NULL)
                     {
                           if(parent->kiri == curr)
                           {
                              parent->kiri = curr->kanan;
                              delete curr;
                         }
                         else 
                         {
                              parent->kanan = curr->kanan; 
                              delete curr;
                         }
                     }
                  else
                  {
                           if(parent->kiri == curr)
                           {
                                  parent->kiri = curr->kiri; 
                                  delete curr;
                           }
                           else 
                           {
                               parent->kanan = curr->kiri; 
                               delete curr;
                            }
                   }
                   return;
              }


              if (curr->kiri != NULL && curr->kanan != NULL)
              {
                     Node* bantu;
                     bantu = curr->kanan;

                     if((bantu->kiri == NULL) && (bantu->kanan == NULL))
                     {

                           curr = bantu;
                           delete bantu;
                           curr->kanan = NULL;
                     }
                     else 
                     {
                           if((curr->kanan)->kiri != NULL)
                           {
                                  Node* bantu2;
                                  Node* bantu3; 
                                  bantu3 = curr->kanan;         
                                  bantu2 = (curr->kanan)->kiri; 

                                  while(bantu2->kiri != NULL)
                                  {
                                         bantu3 = bantu2;
                                         bantu2 = bantu2->kiri;
                                  }
                                  curr->data = bantu2->data;
                                  delete bantu2;
                                  bantu3->kiri = NULL;
                        }
                        else 
                        {
                              Node* tmp;
                              tmp = curr->kanan;
                              curr->data = tmp->data;
                              curr->kanan = tmp->kanan;
                              delete tmp;
                        }

                     }
                     return;
              }
       }
}




int main()
{
    char pil;
    int del,cari;
    while (true)
    {
        system("cls"); 
        char data;
        printf("\tBinary Search Tree");
        printf("\n\t==================");
        printf("\nMENU");
        printf("\n----\n");
        printf("[1] Masukkan Data\n");
        printf("[2] Lihat Data Dalam Pre-Order, In-Order, Post-Order\n");
        printf("[3] Cari Data\n");
        printf("[4] Menghapus Node\n");
        printf("[5] Menampilkan Nilai Maks dan Min Dalam Node\n");
        printf("[6] Reset Node\n");
        printf("[0] KELUAR PROGRAM\n");
        printf("Pilihan Anda : ");
        scanf("%c",&pil);
        fflush(stdin); 
        switch(pil)
        {
        	case'0':
        			 exit(0);
                     break;
                     
            case '1':
                     printf("\nINPUT : ");
                     printf("\n-------");
                     printf("\nMasukkan data: ");
                     scanf("%d", &data);
                     insert(&tree,data);
                     _getch();
                      break;

            case '2':
                     printf("\n===== Berikut Data Dalam Pre-Order, In-Order, Post-Order =====");
                     printf("\n------");
                     if(tree!=NULL)
                     {
                           printf("\nPRE-ORDER  : ");
                           preOrder(tree);
                           printf("\nIN-ORDER   : ");
                           inOrder(tree); 
                           printf("\nPOST-ORDER : ");
                           postOrder(tree); 
                     }else
                           printf("\nMasih kosong!");

                     _getch();
                     break;
                     
			case '3':
                     if(tree!=NULL)
                     {
                           printf("\n\n===== Melakukan Pencarian Data ===== ");
                           printf("\n--------------------------------------\n");
                           printf("\nMasukkan data yang ingin dicari : ");
                           scanf("%d", &cari);
                           search(&tree, cari);
                     }
                     else
                           printf("\nNode Kosong");

                     _getch();
                     break;
                     
                     
        	case '4':
					 if(tree!=NULL)
                     {
                           printf("\n\n===== Menghapus Data =====");
                           printf("\n--------------------------\n");
                           printf("Masukkan data yang ingin dihapus: ");
                           scanf("%d", &del);
                           hapus(&tree, del);
                           printf("\n\nNODE TELAH DIHAPUS");
                     }
                     else
                           printf("\nMasih kosong!");

                     _getch();
                     break;	
				
			case '5':
					 printf("\n===== Menampilkan Nilai Maks dan Min Dalam Node ");
                     printf("\n---------------------------------------------\n");
                     if(tree!=NULL)
                     {
                           printf(" Nilai Maksimum Dari Node Adalah : %d \n", Max(tree));
                           printf(" Nilai Mainimum Dari Node Adalah : %d \n", Min(tree));
                       }
                     else
                           printf("Masih Kosong!!!");
                    
                     _getch();
                     break;	 
            case '6':
					 tree=NULL;
                     printf("\n===== MERESET NODE =====");
                     printf("\n-----------------------");
                     printf("\nNode Sudah Di Reset");
                     _getch();
                     break;         
			  }
       }
}
