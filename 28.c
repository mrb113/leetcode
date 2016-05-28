int strStr(char* haystack, char* needle)
{
    int retval = 0;
    if(strlen(needle) == 0)
    {
        return 0;
    }
    for(int i = 0; i < strlen(haystack); i++)
    {
        if((strlen(haystack) - i) >= strlen(needle))
        {
            for(int j = 0; j < strlen(needle); j++)
            {
                if (haystack[i+j] != needle[j])
                {
                    break;
                }
                if(j == strlen(needle) - 1)
                {
                    return i;
                }
            }
        }
    }
    return -1;
}
