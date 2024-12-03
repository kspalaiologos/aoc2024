#include"a.h"
#include<curl/curl.h>
size_t buf_append(C * ptr, size_t size, size_t nmemb, C * buf) {
  size_t len = size * nmemb;
  if (buf + strlen(buf) + len >= buf + 65536) {
    fprintf(stderr, "Buffer overflow.\n");
    exit(1);
  }
  memcpy(buf + strlen(buf), ptr, len);
  return len;
}
I main(I ac, C * av[]) {
  I(ac < 2, R 1);
  C * opt = av[1];
  FILE * cookie = fget("cookie.txt", "r"); // Cookie: session=..., no trail LF.
  C cstr[256] = { 0 }; fread(cstr, 1, 256, cookie);
  CURL * curl = curl_easy_init();
  if(!strcmp(opt, "get-input") && ac == 3) {
    C * url; asprintf(&url, "https://adventofcode.com/2024/day/%d/input", atoi(av[2]));
    C * oname; asprintf(&oname, "d%02d.txt", atoi(av[2]));
    FILE * out = fget(oname, "wb");
    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, fwrite);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, out);
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, curl_slist_append(NULL, cstr));
    I res = curl_easy_perform(curl);
    I(res != CURLE_OK,
      fprintf(stderr, "CURL request failed: %s\n", curl_easy_strerror(res));
      exit(1))
  } else if(!strcmp(opt, "submit") && ac == 5) {
    I day = atoi(av[2]), level = atoi(av[3]);
    C * answer = av[4];
    C * url; asprintf(&url, "https://adventofcode.com/2024/day/%d/answer", day);
    C * content = "Content-Type: application/x-www-form-urlencoded";
    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_POST, 1);
    C * post; asprintf(&post, "level=%d&answer=%s", level, answer);
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, post);
    curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, strlen(post));
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, curl_slist_append(curl_slist_append(NULL, cstr), content));
    C buf[65536] = { 0 };
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, buf_append);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, buf);
    I res = curl_easy_perform(curl);
    I(res != CURLE_OK,
      fprintf(stderr, "CURL request failed: %s\n", curl_easy_strerror(res));
      exit(1))
    I(strstr(buf, "not the right"),
      fprintf(stderr, "Answer not accepted.\n");
      exit(1))
    I(strstr(buf, "too recently"),
      fprintf(stderr, "Answer too recent.\n");
      exit(1))
    E(printf("Answer accepted.\n")) // Needs more failure-oriented programming.
  }
}