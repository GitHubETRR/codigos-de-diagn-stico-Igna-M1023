#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>
//gcc network.c -o network -L"C:/6Tel/LIB/CURL/lib" -lcurl

int main() {
    CURL *curl;
    FILE *fp;
    CURLcode res;
    const char *url = "https://dolarapi.com/v1/dolares/blue";
    const char *outfilename = "downloaded_file.txt";

    curl = curl_easy_init();
    fp = fopen(outfilename, "wb");
    if (!fp) {
        perror("Failed to open file");
        return 1;
    }
    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, NULL);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
    res = curl_easy_perform(curl);
    if (res != CURLE_OK) {
        fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
    }
    fclose(fp);
    curl_easy_cleanup(curl);
    if (!curl) {
        fprintf(stderr, "Failed to initialize CURL\n");
        return 1;
    }
}
