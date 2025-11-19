#include <stdio.h>
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
int encrypt(int data, int key,int valof){
    int n1=data%16;
    int n2=(data/16)%16;
    int n3=(data/256)%16;
    int n4=(data/4096)%16;
    int n5=(data/65536)%16;
    int n6=(data/1048576)%16;
    int n7=(data/16777216)%16;
    int n8=(data/268435456)%16;
    int k1=(key/1)%16;
    int k2=(key/16)%16;
    int k3=(key/256)%16;
    int k4=(key/4096)%16;
    int k5=(key/65536)%16;
    int k6=(key/1048576)%16;
    int k7=(key/16777216)%16;
    int k8=(key/268435456)%16;
    int mattoenc1[]={n1,n2,n3,n4};
    int mattoenc2[]={n5,n6,n7,n8};
    int key1[]={k1+8,k3+8,k5+8,k7+3};
    int key2[]={k2+3,k4+3,k6+2,k8+1};
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
        st3_1[ajkud]=st2_1[ajkud]^(key%16);
        st3_2[ajkud]=st2_2[ajkud]^(key%16);
    }
    if (valof>3){
        return st3_2[valof%4];
    }else {
        return st3_1[valof%4];
    }
}
int decrypt(int *mattoenc1, int *mattoenc2, int key){
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
    int key1[]={k1+8,k3+8,k5+8,k7+3};
    int key2[]={k2+3,k4+3,k6+2,k8+1};
    //first stage
    int st1_1[4];
    int st1_2[4];
    int st2_1[4];
    int st2_2[4];
    for (int ajkd=0;ajkd<4;ajkd++){
        st1_1[ajkd]=mattoenc1[ajkd]^(key%16);
        st1_2[ajkd]=mattoenc2[ajkd]^(key%16);
        
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
    int rslt=(st3_1[0])+(st3_1[1]*16)+(st3_1[2]*256)+(st3_1[3]*4096)+((st3_2[0]%16)*65536)+((st3_2[1]%16)*1048576)+((st3_2[2]%16)*16777216)+((st3_2[3]%16)*268435456);
    return rslt;
}
int main(){
    int naud1[]={4,3,1,1};
    int naud2[]={7,2,9,3};
    int encrpted1[4];
    int encrpted2[4];
    for(int ajkd=0;ajkd<4;ajkd++){
        encrpted1[ajkd]=encrypt(159,139575678,ajkd);
        encrpted2[ajkd]=encrypt(159,139575678,ajkd+4);
        
    }
    int decr=decrypt(encrpted1,encrpted2,139575678);
    printf(" the result is : %d ",decr);
    return 1;
}