#include<stdio.h>
#include<stdlib.h>

int urun_control();
void urun_ekle();
void urun_goster();
void urun_guncelle();
void urun_sil();

char urun_kodu[20]="83401";

int main(){

 int secenek;
 
 printf("Urun kodu giriniz=");
 scanf("%s",&urun_kodu);



    while(1){
   printf("===Yapacaginiz Islemi Seciniz===\n");
   printf("1-Urun kontrolu\n");
   printf("2-Urun Ekleme\n");
   printf("3-Urun Goster\n");
   printf("4-Urun Guncelle\n");
   printf("5-Urun sil\n");
   printf("6-cikis\n");
   printf("secim=");
   scanf("%d",&secenek);

      switch(secenek){
         
         case 1:
          urun_control();
           break;

         case 2: 
           urun_ekle();
             break;
            
         case 3:
            urun_goster();
            break;
          
          case 4: 
             urun_guncelle();
             break;
             
          case 5:
            urun_sil();
            break;
          
            case 6:
              printf("cikis yapiliyor...\n");
              exit(0);
              break;
    
            default:
             printf("gecersiz secim\n");
              break;
      }
  }
  return 0;
}
int urun_control(){
 FILE*file=fopen(urun_kodu,"r");

  if(file){

   fclose(file);
    printf("Urun mevcut : %s\n",urun_kodu);
     return 1;

  }else{
 
    printf("Urun bulunamadi: %s\n",urun_kodu);
    return 0;
  }
}
void urun_ekle(){
   FILE*file = fopen(urun_kodu,"w");
  
   if(file==NULL){
    
    printf("Urun olusturulamadi\n");

   return;
   }
   
   fprintf(file,"Urun olusturuldu ve kodu yazildi.\n");
   fclose(file);
   printf("Urun basariyla olusturuldu\n");

}
void urun_goster(){
 if(!urun_control()){
   printf("Urun bulunamadi gosterme basarisiz\n");
   return;
 }
 FILE*file = fopen(urun_kodu,"r");
 if(file==NULL){
   printf("HATA!\n");
   return;
 }

 char line[100];
   while(fgets(line,sizeof(line),file)!=NULL){
      printf("%s",line);
   }

   fclose(file);
   printf("Urun okundu\n");


}
void urun_guncelle(){

 if(!urun_control()){
   printf("Urun bulunamadı guncelleme basarisiz\n");
   return;
 }
  FILE*file=fopen(urun_kodu,"a");
  if(file==NULL){
   printf("HATA!\n");
   return;
  }
  int num;
  for(int i=1;i<=5;i++){
   printf("bir sayi giriniz");
   scanf("%d",&num);
   fprintf(file,"%d\n",num);
  }
 fclose(file);
 printf("urun kodu guncellendi\n");

}
void urun_sil(){

   if(!urun_control()){
      printf("Urun bulunamadı silme islemi basarisiz\n");
      return;
   }
   if(remove(urun_kodu)==0){
      printf("Urun basariyla silindi\n");
   }else{
      printf("Urun silinemedi!\n");
   }

}