#include <curl/curl.h>
#include <iostream>
static size_t WriteCallback(void* contents,
                            size_t size,
                            size_t nmemb,
                            void* userp) {
  return size * nmemb;
}

int main() {
  CURL* curl;
  CURLcode res;
  char* readtest = NULL;

  curl = curl_easy_init();

  curl_easy_setopt(curl, CURLOPT_URL, "http://127.0.0.1:9998");
  curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
  curl_easy_setopt(curl, CURLOPT_WRITEDATA, readtest);
  curl_easy_cleanup(curl);
  
  std::cout << "TEST" << std::endl;

  
  return 0;
}