 for String compare we have strcmp(), strcmpi(), strncmp() & strncmpi(), all 4 functions return type is int.
  
  return 0 - if both strings r equals. 
  return +ve value - if 1st String greator.
  return -ve value - if 1st String smaller. 

  ** return diff of ASCII code - 

   a = "Aditi";  b = "Aayushi";  , compare char by char - 
                    compare 1st char both string -  A - A - both r equals, 
                    control jump of 2nd char - d(100) - a(97) 

    a = "Sanjay" 
    b = "Sandeep"  , diff of j & d 
          
  if(strcmp(a,b) > 0)  - true   , bcos it return 3 - 

  strcmp(str1,str2) - compare 2 Strings with Case - means case Senstive
  strcmpi(str1,str2) - compare 2 Strings with Ignore Case - means case in-senstive
  strncmp(str1,str2,NOC) - compare No of Chars (NOC) of 2 Strings with Case - means case Senstive
  strncmpi(str1,str2,NOC)- compare No of Chars (NOC) of 2 String with Ignore Case - means case in-senstive

 we want to compare 2 String without using any function. means without using strcmp() + strcmpi() + strncmp(), strncmpi()

  with - for loop / while loop.
          0123456        0123456
  str1 = "Shivam", str2="Shivam Kumar";  

    str1[6] = '\0' (0)  str2[6] = ' ' (32)


  str = "Shwkshi"; str2="Shivam Kumar"; 
         01
       
     str1[2] = w    str2[2] = 'i'

 compare 2 Strings without strcmp() function

-- with for loop -  for(initialize;condition;incr/decr) {}  - condition only one but initialize + incr & desc - any number of separate with ,
    initialize; ...... condition................. 
  for(i = 0; str1[i] == str2[i] && Str1[i] != '\0'; i++);
  if(str1[i] > str2[i])
    printf("\n str1 is Greator than str2");
  else if(str1[i] < str2[i])
    printf("\n str2 is Greator than str1");
  else 
    printf("\n str1 is Equal to str2");

-- with while loop - 

  i=0;
  while(str1[i] == str2[i] && str1[i] == '\0')
    i++;
  if(str1[i] > str2[i])
    printf("\n str1 is Greator than str2");
  else if(str1[i] < str2[i])
    printf("\n str2 is Greator than str1");
  else 
    printf("\n str1 is Equal to str2");
__________________________________________________________

 algo for delete duplicate elements from an array -  int ar[] = {10,20,50,20,10,30,20,30,10} , unique array = 10,20,50,30

  for (i = 0; i < size; i++)  // size - max
  {
    for(j = i + 1; j < Size; j++) // selection algo. 
    {
       if(arr[i] == arr[j])
       {
          for(k = j; k < Size; k++)
    	    arr[k] = arr[k + 1];
          size--;
	  j--;
       }
    }
  }
 
  or

  for (i = 0; i < size; i++)
  {
    for(j = i + 1; j < size;)
    {
       if(arr[i] == arr[j])
       {
    	  for(k = j; k < size; k++)
    	    arr[k] = arr[k + 1];
	  size--;
       }
       else
 	  j++;
    }
  }

   or

   ctr = 0
   for (i = 0; i < size; i++)
   {
     for(j = 0; j < ctr; j++)
     {
    	if(arr[i] == tmp[j])
       	  break;
     }
     if(j == ctr)
     {
	tmp[ctr] = arr[i];
	ctr++;
     }
   }

 ___________________________________________________________

  Write a C program to Toggle Case of all Characters in a String
  input string - Abhay PraTap Singh , output - aBHAY pRAtAP sINGH

   for (i = 0; Str1[i]!='\0'; i++)
   {
      if(str1[i] >= 'a' && str1[i] <= 'z')
  	Str1[i] = Str1[i] - 32;
      else if(str1[i] >= 'A' && str1[i] <= 'Z')
  	Str1[i] = Str1[i] + 32;
   }
_______________________________________

 String Palindrome Program in C - 

  str = "malayalam"
  len = 0;
  while(str[len] != '\0')
    len++;
 	   	
   for(i = 0; i < len; i++)
   {
     if(str[i] != str[len - i - 1])
     {
	flag = 1;
	break;	
     } 
   }
   if(flag == 0)
     printf("\n %s is a Palindrome String", str);
   else
     printf("\n %s is Not a Palindrome String", str);
________________________________________

 Number Palindrome Program in C 

  rev = 0;
  tmp = n;
  while ( tmp > 0)
  {
     x = tmp %10;
     rev = rev * 10+ rev;
     tmp = tmp / 10;
  }
  if ( n == rev)
     printf("\n%d is Palindrome Number.\n", n);
  else
     printf("%d is not the Palindrome Number.\n", n);
__________________________________________

-- C Program String reverse word by word. 

  len = 0;
  while(str[len] != '\0')
     len++;
  end = len - 1;  // end - contain the end of the word. 
  for(i = len - 1; i >= 0; i--) // loop - whole String.
  {
     if(str[i] == ' ' || i == 0) // ' ' - mid , i==0 - 1st word  
     {
	if(i == 0)
	   start = 0;
	else
	   start = i + 1;
        for(j = start; j <= end; j++)
          printf("%c", str[j]);
        end = i - 1;
        printf(" ");				
     }
  } 

  HIET College Ghaziabad Uttar Pradesh

  Pradesh Uttar Ghaziabad College HIET
______________________________________________   	

// C program to find the frequency of characters in a string

   while (str[c] != '\0') {
     if (str[c] >= 'a' && str[c] <= 'z') {
       x = str[c] - 'a';
       count[x]++;
     }
     c++;
   }

   for (c = 0; c < 26; c++)
      printf("%c occurs %d times in the string.\n", c + 'a', count[c]);


 Problem in Last classes - 2:30pm -   9990046906 
