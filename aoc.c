#include"a.h"
#include<curl/curl.h>
I main(I ac, C * av[]) {
  if(ac < 2) R 1;
  C * opt = av[1];
  if(!strcmp(opt, "get-input") && ac == 3) {
    C * url; asprintf(&url, "https://adventofcode.com/2024/day/%d/input", atoi(av[2]));
    FILE * cookie = fget("cookie.txt", "r"); // Cookie: session=..., no trail LF.
    C cstr[256]; fread(cstr, 1, 256, cookie);
    CURL * curl = curl_easy_init();
    C * oname; asprintf(&oname, "d%02d.txt", atoi(av[2]));
    FILE * out = fget(oname, "w");
    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, fwrite);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, out);
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, curl_slist_append(NULL, cstr));
    int res = curl_easy_perform(curl);
    I(res != CURLE_OK,
      fprintf(stderr, "CURL request failed: %s\n", curl_easy_strerror(res));
      exit(1))
  }
}