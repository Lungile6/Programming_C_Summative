# Multi-threaded Web Scraper (C + libcurl + pthreads)

## Description
A simple web scraper that fetches multiple URLs in parallel using threads. Each URL's HTML content is saved to a separate file in the `output/` folder.

## Features
- Parallel downloads via POSIX threads
- One file per page (`page_1.html`, `page_2.html`, ...)
- Built-in error handling for failed URLs

## Dependencies
- `libcurl`: Install with `sudo apt install libcurl4-openssl-dev`

## Build
```bash
make
