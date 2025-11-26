#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
int maxmul(int *nums1,int *nums2,int nto){
    int nu1=nums1[0]*nums2[0]+nums1[1]*nums2[2];
    int nu2=nums1[0]*nums2[1]+nums1[1]*nums2[3];
    int nu3=nums1[2]*nums2[0]+nums1[3]*nums2[2];
    int nu4=nums1[2]*nums2[1]+nums1[3]*nums2[3];
    int resl[4]={nu1,nu2,nu3,nu4};
    return resl[nto];
}
int matinv(int *mat,int nded){
    int det=mat[0]*mat[3]-mat[1]*mat[2];
    int n1=mat[3];
    int n2=-mat[1];
    int n3=-mat[2];
    int n4=mat[0];
    int reus[]={n1,n2,n3,n4,det};
    if (det==0){
        printf("errror ! division by zero ! ");
    }
    return reus[nded];
}
int matadd(int *mat1,int *mat2,int nto){
    int arr[4];
    for (int jdu=0;jdu<4;jdu++){
        arr[jdu]=mat1[jdu]+mat2[jdu];
    }
    return arr[nto];
}
int matsub(int *mat1,int *mat2,int nto){
    int arr[4];
    for (int jdu=0;jdu<4;jdu++){
        arr[jdu]=mat1[jdu]-mat2[jdu];
    }
    return arr[nto];
}
int encode(int data,int valof){
    int n1=data%16;
    int n2=(data/16)%16;
    int n3=(data/256)%16;
    int n4=(data/4096)%16;
    int n5=(data/65536)%16;
    int n6=(data/1048576)%16;
    int n7=(data/16777216)%16;
    int n8=(data/268435456)%16;
    int mattoenc1[]={n1,n2,n3,n4};
    int mattoenc2[]={n5,n6,n7,n8};
    if (valof>3){
        return mattoenc2[valof%4];
    }else{
        return mattoenc1[valof%4];
    }
}
int decode(int *st3_1,int *st3_2){
    int rslt=(st3_1[0])+(st3_1[1]*16)+(st3_1[2]*256)+(st3_1[3]*4096)+((st3_2[0]%16)*65536)+((st3_2[1]%16)*1048576)+((st3_2[2]%16)*16777216)+((st3_2[3]%16)*268435456);
    return rslt;
}
int encrypt1(int *mattoenc1,int *mattoenc2, int key,int valof){
    /*int n1=data%16;
    int n2=(data/16)%16;
    int n3=(data/256)%16;
    int n4=(data/4096)%16;
    int n5=(data/65536)%16;
    int n6=(data/1048576)%16;
    int n7=(data/16777216)%16;
    int n8=(data/268435456)%16;*/
    int k1=(key/1)%16;
    int k2=(key/16)%16;
    int k3=(key/256)%16;
    int k4=(key/4096)%16;
    int k5=(key/65536)%16;
    int k6=(key/1048576)%16;
    int k7=(key/16777216)%16;
    int k8=(key/268435456)%16;
    //int mattoenc1[]={n1,n2,n3,n4};
    //int mattoenc2[]={n5,n6,n7,n8};
    int key1[]={k1+1,k3+1,k5+1,k7+1};
    int key2[]={k2+1,k4+1,k6+1,k8+1};
    //first stage
    
    int st1_1[4];
    int st1_2[4];
    for (int ajkud=0;ajkud<4;ajkud++){
        st1_1[ajkud]=matadd(mattoenc1,key1,ajkud);
        st1_2[ajkud]=maxmul(mattoenc2,key2,ajkud);
    }
    int st2_1[4];
    int st2_2[4];
    for (int ajkud=0;ajkud<4;ajkud++){
        st2_1[ajkud]=maxmul(st1_1,key2,ajkud);
        st2_2[ajkud]=matadd(st1_2,key1,ajkud);
    }
    int st3_1[4];
    int st3_2[4];
    for (int ajkud=0;ajkud<4;ajkud++){
        st3_1[ajkud]=st2_1[ajkud]^(key);
        st3_2[ajkud]=st2_2[ajkud]^(key);
    }
    int st4_1[4];
    int st4_2[4];
    for (int ajkd=0;ajkd<4;ajkd++){
        st4_1[ajkd]=st3_1[(ajkd+(key%4))%4]; 
        st4_2[ajkd]=st3_2[(ajkd+(key%4))%4];
    }
    if (valof>3){
        return st4_2[valof%4];
    }else {
        return st4_1[valof%4];
    }
}
int decrypt1(int *mattoenc1, int *mattoenc2, int key,int valof){
    /*int n1=data%16;
    int n2=(data/16)%16;
    int n3=(data/256)%16;
    int n4=(data/4096)%16;
    int n5=(data/65536)%16;
    int n6=(data/1048576)%16;
    int n7=(data/16777216)%16;
    int n8=(data/268435456)%16;*/
    int k1=(key/1)%16;
    int k2=(key/16)%16;
    int k3=(key/256)%16;
    int k4=(key/4096)%16;
    int k5=(key/65536)%16;
    int k6=(key/1048576)%16;
    int k7=(key/16777216)%16;
    int k8=(key/268435456)%16;
    int key1[]={k1+1,k3+1,k5+1,k7+1};
    int key2[]={k2+1,k4+1,k6+1,k8+1};
    //first stage
    int st1_1[4];
    int st1_2[4];
    int st2_1[4];
    int st2_2[4];
    int st0_1[4];
    int st0_2[4];
    for (int ajkd=0;ajkd<4;ajkd++){
        st0_1[(ajkd+(key%4))%4]=mattoenc1[ajkd]; 
        st0_2[(ajkd+(key%4))%4]=mattoenc2[ajkd];
    }
    for (int ajkd=0;ajkd<4;ajkd++){
        st1_1[ajkd]=st0_1[ajkd]^(key);
        st1_2[ajkd]=st0_2[ajkd]^(key);
        
    }
    int unkey1[5];
    int unkey2[5];

    for (int ajkud=0;ajkud<5;ajkud++){
        unkey1[ajkud]=matinv(key1,ajkud);
        unkey2[ajkud]=matinv(key2,ajkud);
    }
    for (int ajkd=0;ajkd<4;ajkd++){
        st2_1[ajkd]=(maxmul(st1_1,unkey2,ajkd))/unkey2[4];
        st2_2[ajkd]=matsub(st1_2,key1,ajkd);
        
    }
    int st3_1[4];
    int st3_2[4];
    for (int ajkd=0;ajkd<4;ajkd++){
        st3_1[ajkd]=matsub(st2_1,key1,ajkd); 
        st3_2[ajkd]=(maxmul(st2_2,unkey2,ajkd))/unkey2[4];
    }
    if(valof>3){
        return st3_2[valof%4];
    }else{
        return st3_1[valof%4];
    }
}
int checkky(int *keys){
    for(int ajkd=0;ajkd<2;ajkd++){
    int key=keys[ajkd];
    int k1=(key/1)%16;
    int k2=(key/16)%16;
    int k3=(key/256)%16;
    int k4=(key/4096)%16;
    int k5=(key/65536)%16;
    int k6=(key/1048576)%16;
    int k7=(key/16777216)%16;
    int k8=(key/268435456)%16;
    int key1[]={k1+1,k3+1,k5+1,k7+1};
    int key2[]={k2+1,k4+1,k6+1,k8+1};
    int da=matinv(key1,4);
    int db=matinv(key2,4);
    if ((da==0) or (db==0)){
        printf("\n no ! no ! no ! stooop !! \n ");
        return 3221225620;
    }
    }
    return 1;
}
int encrypt(int tocrypt, int *keys,int *rasu1,int *rasu2){
    int mattoenc1[4];
    int mattoenc2[4];
    for(int ajkd=0;ajkd<4;ajkd++){
        mattoenc1[ajkd]=encode(tocrypt,ajkd);
        mattoenc2[ajkd]=encode(tocrypt,ajkd+4);
    }
    int rsu1[4];
    int rsu2[4];
    int vali=checkky(keys);
    if (vali==3221225620){
        printf("\n no , be careful  careful now ! \n");
        return 0;
    }
    for(int ajkd=0;ajkd<4;ajkd++){
        rsu1[ajkd]=encrypt1(mattoenc1,mattoenc2,keys[0],ajkd);
        rsu2[ajkd]=encrypt1(mattoenc1,mattoenc2,keys[0],ajkd+4);
    }
    for(int ajkd=0;ajkd<4;ajkd++){
        rasu1[ajkd]=encrypt1(rsu1,rsu2,keys[1],ajkd);
        rasu2[ajkd]=encrypt1(rsu1,rsu2,keys[1],ajkd+4);
    }
    return 0;
}
int decrypt(int *mattoenc1, int *mattoenc2, int *keys){
    int rasu1[4];
    int rasu2[4];
    int rsu1[4];
    int rsu2[4];
    for(int ajkd=0;ajkd<4;ajkd++){
        rsu1[ajkd]=decrypt1(mattoenc1,mattoenc2,keys[1],ajkd);
        rsu2[ajkd]=decrypt1(mattoenc1,mattoenc2,keys[1],ajkd+4);
    }
    for(int ajkd=0;ajkd<4;ajkd++){
        rasu1[ajkd]=decrypt1(rsu1,rsu2,keys[0],ajkd);
        rasu2[ajkd]=decrypt1(rsu1,rsu2,keys[0],ajkd+4);
    }
    int decr=decode(rasu1,rasu2);
    return decr;
}
void readthis(int *wheretoput,int bufsiz){
    int lau[64];
    char xi[64];
    FILE *deta =fopen("toen1.txt","r");
    for(int axu=0;axu<bufsiz;axu++){
        fgets(xi,64,deta);
        lau[axu]=atoi(xi);
        wheretoput[axu]=lau[axu];
        //printf("result is : %d \n",lau[axu]);
    }
    fclose(deta);
    
}
int countthis(int endec) {
    FILE *fp;
    if(endec==0){
        fp=fopen("toen1.txt","r");
    }else{
        fp=fopen("todec.txt","r");
    }
    int count = 0, tmp;
    while (fscanf(fp, "%d", &tmp) == 1) count++;
    rewind(fp);
    fclose(fp);
    return count;
}
void settham(int *encrpteded,int leen){
FILE *fp=fopen("encrted1.txt","w");
for (int axu=0;axu<leen;axu++){
    fprintf(fp,"%d\n",encrpteded[axu]);
}
fclose(fp);
}
void readthat(int *wheretoput,int bufsiz){
    char xi[64];
    FILE *deta =fopen("todec.txt","r");
    for(int axu=0;axu<bufsiz;axu++){
        fgets(xi,64,deta);
        wheretoput[axu]=atoi(xi);
    }
    fclose(deta);
}
void setthos(int *whattopu,int sizeo){
    FILE *nums =fopen("dected.txt","w");
    for(int axu=0;axu<sizeo;axu++){
        fprintf(nums,"%d\n",whattopu[axu]);
    }
    fclose(nums);
}
int main(){
    while(1==1){
    int onelen=countthis(0);
    int arruru[onelen];
    int reslte[onelen*8];
    readthis(arruru,onelen);
    int encrpted1[4];
    int encrpted2[4];
    int keys[2]={15469,98576};
    for(int axu=0; axu<onelen ;axu++){
    encrypt(arruru[axu],keys,encrpted1,encrpted2);
    reslte[(axu*8)]=encrpted1[0];
    reslte[(axu*8)+1]=encrpted1[1];
    reslte[(axu*8)+2]=encrpted1[2];
    reslte[(axu*8)+3]=encrpted1[3];
    reslte[(axu*8)+4]=encrpted2[0];
    reslte[(axu*8)+5]=encrpted2[1];
    reslte[(axu*8)+6]=encrpted2[2];
    reslte[(axu*8)+7]=encrpted2[3];
    }
    int leen1=sizeof(reslte)/sizeof(reslte[0]);
    settham(reslte,leen1);

    //stop 


     onelen=countthis(1);
    int arru[onelen];
    int reslte1[(onelen/8)];
    readthat(arru,onelen);
    int decrypted;
    int are1[4];
    int are2[4];
    
    for(int axu=0;axu<(onelen/8) ;axu++){
    are1[0]=arru[(axu*8)];
    are1[1]=arru[(axu*8)+1];
    are1[2]=arru[(axu*8)+2];
    are1[3]=arru[(axu*8)+3];
    are2[0]=arru[(axu*8)+4];
    are2[1]=arru[(axu*8)+5];
    are2[2]=arru[(axu*8)+6];
    are2[3]=arru[(axu*8)+7];
    decrypted=decrypt(are1,are2,keys);
    reslte1[axu]=decrypted;
    }
    int aju=sizeof(reslte1)/sizeof(reslte1[0]);
    setthos(reslte1,aju);
    
    Sleep(850);
    printf("working ... \n");
}
return 0;
}