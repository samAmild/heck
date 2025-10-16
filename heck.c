#include <stdio.h>
#include <string.h>

void force_index_php(const char *url, char *output) {
    const char *start = strstr(url, "://");
    if (start) {
        start += 3;  // Skip "://"
    } else {
        start = url; // No scheme, start from beginni>
    }

    const char *end = strchr(start, '/');
    size_t domain_len = end ? (size_t)(end - start) :>

    strncpy(output, start, domain_len);
    output[domain_len] = '\0';
    strcat(output, "/index.php");
}

int main() {
    const char *urls[] = {
    "",  // put your first URL here
    "",  // put your second URL here
    "",  // put your third URL here
    "",  // add more as needed
};

    char result[256];
    for (int i = 0; i < sizeof(urls)/sizeof(urls[0]);>
        force_index_php(urls[i], result);
        printf("Original: %s\nModified: %s\n\n", urls>
    }

    return 0;
}
