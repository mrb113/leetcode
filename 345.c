char* reverseVowels(char* s) {
    int right = strlen(s) - 1;
    int left = 0;
    char temp;
    const char* matches = "aeiouAEIOU";

    while(left < right)
    {
        if (strchr(matches, s[left]) == NULL)
        {
            left++;
            continue;
        }
        
        if (strchr(matches, s[right]) == NULL)
        {
            right--;
            continue;
        }
        temp = s[left];
        s[left] = s[right];
        s[right] = temp;
        left++;
        right--;
    }
    
    return s;
}
