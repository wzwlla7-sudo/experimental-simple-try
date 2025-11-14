#include <stdio.h>
int maxmul(int *nums1,int *nums2,int nto){
    int nu1=nums1[0]*nums2[0]+nums1[1]*nums2[2];
    int nu2=nums1[0]*nums2[1]+nums1[1]*nums2[3];
    int nu3=nums1[2]*nums2[0]+nums1[3]*nums2[2];
    int nu4=nums1[2]*nums2[1]+nums1[3]*nums2[3];
    int resl[4]={nu1,nu2,nu3,nu4};
    return resl[nto];
}
int matinv(int *mat,nded){
    int det=mat[0]*mat[3]-mat[1]*mat[2];
    int n1=mat[3];
    int n2=-mat[1];
    int n3=-mat[2];
    int n4=mat[0];
    int reus[]=[n1,n2,n3,n4,det];
    return reus[nded];
}
int encrypt(int data, int key){
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

    return 0;
return 0;
}
int main(){
    int naud1[]={4,3,1,1};
    int naud2[]={7,2,9,3};
    int cha=maxmul(naud1,naud2,3);
    printf(" %d \n",cha);
    return 1;
}