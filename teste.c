    #include<stdio.h>
    #include<string.h>
     
    static kmp(char *ptr_i,char *ptr_m,int word_length,int sentence_length);
    static kmp_table(char *ptr_i,char *ptr_m,int word_length,int sentence_length);
    char T[50];
     
    int main()
    {
    char word[10],sentence[40];
    char *ptr_i,*ptr_m;
    int word_length,sentence_length;
    ptr_i=word;
    ptr_m=sentence;
    printf("Enter the word");
    scanf("%s",&word);
    word_length=strlen(word);
    getchar();
    printf("Enter the sentence\n");
    fgets(sentence,40,stdin);
    sentence_length=strlen(sentence);
    kmp_table(ptr_i,ptr_m,word_length,sentence_length);
    kmp(ptr_i,ptr_m,word_length,sentence_length);
     
    }
     
    kmp(char *ptr_i,char *ptr_m,int word_length,int sentence_length)
    {
    int pos,m=0,i=0;
    for(;m<sentence_length; )
    {
    if(*(ptr_i+i) == *(ptr_m+m+i))
    {
    i=i+1;
    if(i==word_length)
    {
    pos=m+1;
    printf("The word was found at position %d\n",pos );
    }
     
    }
    else
    {
     
    m=m+i-T[i];
    if(i>0)
    i=T[i];
     
    }
    }
     
    return sentence_length;
    }
     
     
    kmp_table(char *ptr_i,char *ptr_m,int word_length,int sentence_length)
    {
    int i,j;
    i=2;
    j=0;
    T[0]=-1;
    T[1]=0;
    for(;i<word_length; )
    {
    if(*(ptr_i+i-1) == *(ptr_i+j))
    {
    T[i]=j+1;
    i=i+1;
    j=j+1;
    }
     
    else if(j>0)
    {
    j=T[j];
    }
     
    else
    {
    T[i]=0;
    i=i+1;
    }
    }
     
     
    }
