// Problem Statement
// Given a URL `startUrl` and an interface `HtmlParser`, implement a multi-threaded web crawler to crawl all links 
// that are under the same hostname as `startUrl`.

// Return all URLs obtained by your web crawler in any order.

// Your crawler should:
// 1. Start from the page: `startUrl`.
// 2. Call `HtmlParser.getUrls(url)` to get all URLs from a webpage of a given URL.
// 3. Do not crawl the same link twice.
// 4. Explore only the links that are under the same hostname as `startUrl`.

// Notes:
// - The hostname is the domain part of the URL (e.g., `example.org` in `http://example.org/test`).
// - Assume all URLs use the HTTP protocol without any port specified.
// - For example, the URLs `http://leetcode.com/problems` and `http://leetcode.com/contest` are under the same hostname, 
//   while `http://example.org/test` and `http://example.com/abc` are not under the same hostname.

// The `HtmlParser` interface is defined as follows:
// interface HtmlParser {
//   // Return a list of all URLs from a webpage of the given URL.
//   // This is a blocking call, meaning it will perform an HTTP request and return when the request is finished.
//   public List<String> getUrls(String url);
// }

// Example 1:
// Input:
// urls = [
//   "http://news.yahoo.com",
//   "http://news.yahoo.com/news",
//   "http://news.yahoo.com/news/topics/",
//   "http://news.google.com",
//   "http://news.yahoo.com/us"
// ]
// edges = [[2,0],[2,1],[3,2],[3,1],[0,4]]
// startUrl = "http://news.yahoo.com/news/topics/"
// Output: [
//   "http://news.yahoo.com",
//   "http://news.yahoo.com/news",
//   "http://news.yahoo.com/news/topics/",
//   "http://news.yahoo.com/us"
// ]

// Example 2:
// Input:
// urls = [
//   "http://news.yahoo.com",
//   "http://news.yahoo.com/news",
//   "http://news.yahoo.com/news/topics/",
//   "http://news.google.com"
// ]
// edges = [[0,2],[2,1],[3,2],[3,1],[3,0]]
// startUrl = "http://news.google.com"
// Output: ["http://news.google.com"]
// Explanation: The startUrl links to all other pages that do not share the same hostname.

// Constraints:
// - 1 <= urls.length <= 1000
// - 1 <= urls[i].length <= 300
// - `startUrl` is one of the URLs.
// - Hostname labels must be valid as per the restrictions on valid hostnames (e.g., length, allowed characters).
// - Assume there are no duplicate URLs in the library.

// Follow-up:
// 1. Assume we have 10,000 nodes and 1 billion URLs to crawl. How would you minimize communication between machines 
//    and ensure equal workload distribution?
// 2. What if one node fails or does not work?
// 3. How do you know when the crawler is done?

interface HtmlParser {
    List<String> getUrls(String url);
}

class Solution {
    private String targetHostName;
    private ConcurrentHashMap<String, Boolean> visitedUrls = new ConcurrentHashMap<>();
    private ExecutorService threadPool = Executors.newFixedThreadPool(5);
    private AtomicInteger activeTasks = new AtomicInteger(0);
    private HtmlParser htmlParser;

    private class CrawlTask implements Runnable {
        private String currentUrl;

        public CrawlTask(String currentUrl) {
            this.currentUrl = currentUrl;
        }

        @Override
        public void run() {
            for (String nextUrl : htmlParser.getUrls(currentUrl)) {
                String nextHostName = nextUrl.split("/")[2];
                if (nextHostName.equals(targetHostName) && visitedUrls.putIfAbsent(nextUrl, true) == null) {
                    activeTasks.incrementAndGet();
                    threadPool.submit(new CrawlTask(nextUrl));
                }
            }
            activeTasks.decrementAndGet();
        }
    }

    public List<String> crawl(String startUrl, HtmlParser htmlParser) {
        this.targetHostName = startUrl.split("/")[2];
        this.htmlParser = htmlParser;

        visitedUrls.put(startUrl, true);
        activeTasks.incrementAndGet();
        threadPool.submit(new CrawlTask(startUrl));

        while (activeTasks.get() > 0) {
            try {
                Thread.sleep(50); // Small delay to reduce busy waiting
            } catch (InterruptedException e) {
                Thread.currentThread().interrupt();
            }
        }

        threadPool.shutdown();
        return new ArrayList<>(visitedUrls.keySet());
    }
}
