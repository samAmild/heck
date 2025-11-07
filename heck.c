#include <stdio.h>
#include <string.h>

void force_index_php(const char *url, char *output) {
    const char *start = strstr(url, "://");
    if (start) {
        start += 3;  // Skip "://"
    } else {
        start = url; // No scheme, start from beginning
    }

    const char *end = strchr(start, '/');
    size_t domain_len = end ? (size_t)(end - start) : strlen(start);

    strncpy(output, start, domain_len);
    output[domain_len] = '\0';
    strcat(output, "/index.php");
}

int main() {
    const char *urls[] = {
        "https://example.com/page",
        "http://test.org",
        "www.site.net/home",
        "plainurl.com"
    };

    char result[256];
    for (int i = 0; i < sizeof(urls) / sizeof(urls[0]); i++) {
        force_index_php(urls[i], result);
        printf("Original: %s\nModified: %s\n\n", urls[i], result);
    }

    return 0;
}
