#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <climits>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <vector>
#include <string>
using namespace std;
// ==========================================
// URL MANAGER
// Uses a hash map to store URLs and servers
// ==========================================
class URLManager
{
    unordered_map<string, string> urlTable;

public:
    void addURL(const string &url, const string &server)
    {
        urlTable[url] = server;
        cout << "URL added successfully!\n";
    }

    // Search for a URL in the hash map
    void searchURL(const string &url)
    {
        auto it = urlTable.find(url);

        if (it != urlTable.end())
            cout << "Stored on Server: " << it->second << "\n";
        else
            cout << "URL not found.\n";
    }
    // Delete a URL if it exists
    void deleteURL(const string &url)
    {
        if (urlTable.erase(url))
            cout << "URL deleted successfully.\n";
        else
            cout << "URL not found.\n";
    }
    // Display all stored URLs
    void displayURLs()
    {
        if (urlTable.empty())
        {
            cout << "No URLs stored.\n";
            return;
        }

        cout << "\n------ URL DATABASE ------\n";

        for (const auto &item : urlTable)
        {
            cout << item.first << " --> " << item.second << "\n";
        }
    }
};
// ==========================================
// SESSION MANAGER
// Stack is used to support undo operations
// ==========================================
class SessionManager
{
    stack<string> history;

public:
    void addAction(const string &action)
    {
        history.push(action);
        cout << "Action stored.\n";
    }
    // Undo the latest action
    void undoAction()
    {
        if (history.empty())
        {
            cout << "Nothing to undo.\n";
            return;
        }

        cout << "Undo: " << history.top() << "\n";
        history.pop();
    }
    // Show history without changing it
    void displayHistory()
    {
        if (history.empty())
        {
            cout << "No session history.\n";
            return;
        }

        stack<string> temp = history;

        cout << "\n---- Session History ----\n";

        while (!temp.empty())
        {
            cout << temp.top() << "\n";
            temp.pop();
        }
    }
};

// ==========================================
// DOWNLOAD QUEUE
// Queue processes downloads in FIFO order
// ==========================================
class DownloadQueue
{
    queue<string> downloads;

public:
    void addDownload(const string &file)
    {
        downloads.push(file);
        cout << "Request added.\n";
    }

    // Process the first download request
    void processDownload()
    {
        if (downloads.empty())
        {
            cout << "Queue Empty.\n";
            return;
        }

        cout << "Processing: " << downloads.front() << "\n";
        downloads.pop();
    }

    // Display all pending downloads
    void displayQueue()
    {
        if (downloads.empty())
        {
            cout << "No pending downloads.\n";
            return;
        }

        queue<string> temp = downloads;

        cout << "\n---- Download Queue ----\n";

        while (!temp.empty())
        {
            cout << temp.front() << "\n";
            temp.pop();
        }
    }
};
// ==========================================
// SERVER DIRECTORY
// Stores server names and searches using Binary Search
// ==========================================
class ServerDirectory
{
    vector<string> servers;

public:
    // Add a new server and keep the list sorted
    void addServer(const string &name)
    {
        servers.push_back(name);
        sort(servers.begin(), servers.end());
        cout << "Server added successfully.\n";
    }

    // Display all servers
    void displayServers()
    {
        if (servers.empty())
        {
            cout << "No servers available.\n";
            return;
        }

        cout << "\n----- SERVERS -----\n";

        for (const auto &server : servers)
        {
            cout << server << "\n";
        }
    }

    // Search for a server using Binary Search
    void searchServer(const string &name)
    {
        int left = 0;
        int right = servers.size() - 1;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;

            if (servers[mid] == name)
            {
                cout << "Server Found!\n";
                return;
            }

            if (servers[mid] < name)
                left = mid + 1;
            else
                right = mid - 1;
        }

        cout << "Server Not Found.\n";
    }
};

// ==========================================
// POPULARITY MANAGER
// Uses Merge Sort to rank files by requests
// ==========================================

struct FileData
{
    string fileName;
    int requests;
};

class PopularityManager
{
    vector<FileData> files;

private:
    // Merge two sorted halves
    void merge(vector<FileData> &arr, int l, int m, int r)
    {

        int n1 = m - l + 1;
        int n2 = r - m;

        vector<FileData> left(n1);
        vector<FileData> right(n2);

        for (int i = 0; i < n1; i++)
            left[i] = arr[l + i];

        for (int j = 0; j < n2; j++)
            right[j] = arr[m + 1 + j];

        int i = 0;
        int j = 0;
        int k = l;

        while (i < n1 && j < n2)
        {

            if (left[i].requests >= right[j].requests)
                arr[k++] = left[i++];
            else
                arr[k++] = right[j++];
        }

        while (i < n1)
            arr[k++] = left[i++];

        while (j < n2)
            arr[k++] = right[j++];
    }

    // Recursive Merge Sort
    void mergeSort(vector<FileData> &arr, int l, int r)
    {

        if (l >= r)
            return;

        int mid = l + (r - l) / 2;

        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);

        merge(arr, l, mid, r);
    }

public:
    // Add file information
    void addFile(const string &name, int count)
    {
        files.push_back({name, count});
    }

    // Display files sorted by popularity
    void displayPopularity()
    {

        if (files.empty())
        {
            cout << "No files available.\n";
            return;
        }

        mergeSort(files, 0, files.size() - 1);

        cout << "\n----- FILE POPULARITY -----\n";

        for (const auto &file : files)
        {
            cout << file.fileName
                 << "  Requests: "
                 << file.requests
                 << "\n";
        }
    }
};
// ==========================================
// CACHE MANAGER
// Linked list used to store cached files
// ==========================================

struct CacheNode
{
    string file;
    CacheNode *next;

    CacheNode(const string &f)
    {
        file = f;
        next = nullptr;
    }
};

class CacheManager
{
    CacheNode *head = nullptr;

public:
    // Insert a new file into the cache
    void insertFile(const string &name)
    {

        if (!head)
        {
            head = new CacheNode(name);
            return;
        }

        CacheNode *temp = head;

        while (temp->next != nullptr)
        {
            temp = temp->next;
        }

        temp->next = new CacheNode(name);
    }

    // Delete a file from the cache
    void deleteFile(const string &name)
    {

        if (!head)
        {
            cout << "Cache Empty.\n";
            return;
        }

        // If the first node matches
        if (head->file == name)
        {
            CacheNode *temp = head;
            head = head->next;
            delete temp;

            cout << "Deleted.\n";
            return;
        }

        CacheNode *curr = head;

        while (curr->next && curr->next->file != name)
        {
            curr = curr->next;
        }

        if (!curr->next)
        {
            cout << "File not found.\n";
            return;
        }

        CacheNode *temp = curr->next;
        curr->next = temp->next;
        delete temp;

        cout << "Deleted.\n";
    }

    // Display all cached files
    void displayCache()
    {

        if (!head)
        {
            cout << "Cache Empty.\n";
            return;
        }

        cout << "\n----- CACHE -----\n";

        CacheNode *temp = head;

        while (temp != nullptr)
        {
            cout << temp->file << "\n";
            temp = temp->next;
        }
    }
};

// ==========================================
// NETWORK GRAPH
// Represents CDN servers and connections
// ==========================================

class NetworkGraph
{

    map<string, vector<pair<string, int>>> graph;

    // Helper function for DFS
    void dfsHelper(const string &node,
                   map<string, bool> &visited)
    {

        visited[node] = true;
        cout << node << " ";

        for (const auto &neighbour : graph[node])
        {

            if (!visited[neighbour.first])
            {
                dfsHelper(neighbour.first, visited);
            }
        }
    }

public:
    // Connect two servers with latency
    void addConnection(const string &src,
                       const string &dest,
                       int latency)
    {

        graph[src].push_back({dest, latency});
        graph[dest].push_back({src, latency});

        cout << "Connection Added Successfully.\n";
    }

    // Display the complete network
    void displayGraph()
    {

        cout << "\n========= CDN NETWORK =========\n";

        for (const auto &node : graph)
        {

            cout << node.first << " -> ";

            for (const auto &edge : node.second)
            {

                cout << "("
                     << edge.first
                     << ", "
                     << edge.second
                     << "ms) ";
            }

            cout << "\n";
        }
    }

    // Breadth First Search
    void BFS(const string &start)
    {

        if (graph.find(start) == graph.end())
        {
            cout << "Server not found.\n";
            return;
        }

        map<string, bool> visited;
        queue<string> q;

        visited[start] = true;
        q.push(start);

        cout << "\nBFS Traversal:\n";

        while (!q.empty())
        {

            string current = q.front();
            q.pop();

            cout << current << " ";

            for (const auto &neighbour : graph[current])
            {

                if (!visited[neighbour.first])
                {

                    visited[neighbour.first] = true;
                    q.push(neighbour.first);
                }
            }
        }

        cout << "\n";
    }

    // Start DFS traversal
    void DFS(const string &start)
    {

        if (graph.find(start) == graph.end())
        {
            cout << "Server not found.\n";
            return;
        }

        map<string, bool> visited;

        cout << "\nDFS Traversal:\n";

        dfsHelper(start, visited);

        cout << "\n";
    }
    // Find the shortest path between two servers
    void shortestPath(const string &src, const string &dest)
    {

        if (graph.find(src) == graph.end() ||
            graph.find(dest) == graph.end())
        {

            cout << "Invalid Server Name.\n";
            return;
        }

        map<string, int> dist;
        map<string, string> parent;

        // Initialize all distances
        for (const auto &node : graph)
        {
            dist[node.first] = INT_MAX;
        }

        dist[src] = 0;

        // Min-priority queue using set
        set<pair<int, string>> pq;
        pq.insert({0, src});

        while (!pq.empty())
        {

            auto current = *pq.begin();
            pq.erase(pq.begin());

            int currentDistance = current.first;
            string currentNode = current.second;

            // Check all neighbours
            for (const auto &neighbour : graph[currentNode])
            {

                string nextNode = neighbour.first;
                int weight = neighbour.second;

                if (currentDistance + weight < dist[nextNode])
                {

                    pq.erase({dist[nextNode], nextNode});

                    dist[nextNode] = currentDistance + weight;
                    parent[nextNode] = currentNode;

                    pq.insert({dist[nextNode], nextNode});
                }
            }
        }

        if (dist[dest] == INT_MAX)
        {
            cout << "No Path Exists.\n";
            return;
        }

        cout << "\nShortest Latency: "
             << dist[dest]
             << " ms\n";

        cout << "Path: ";

        vector<string> path;
        string current = dest;

        // Build the path by tracing parents
        while (current != src)
        {
            path.push_back(current);
            current = parent[current];
        }

        path.push_back(src);

        reverse(path.begin(), path.end());

        for (size_t i = 0; i < path.size(); i++)
        {

            cout << path[i];

            if (i != path.size() - 1)
                cout << " -> ";
        }

        cout << "\n";
    }
};
int main()
{

    URLManager um;
    SessionManager sm;
    DownloadQueue dq;
    ServerDirectory sd;
    PopularityManager pm;
    CacheManager cm;
    NetworkGraph ng;

    int choice;
    int val;

    string s1, s2;

    // Helper function to take string input
    auto getStr = [&](const string &prompt)
    {
        cout << prompt;

        string input;
        getline(cin, input);

        return input;
    };

    do
    {

        cout << "\n=== CLOUD CDN EDGE CACHE ALLOCATOR ===\n";
        cout << "1. Add URL\t\t2. Search URL\n";
        cout << "3. Delete URL\t\t4. Display URLs\n";
        cout << "5. Add Action\t\t6. Undo Action\n";
        cout << "7. Display History\n";
        cout << "8. Add Download\t\t9. Process Download\n";
        cout << "10. Display Queue\n";
        cout << "11. Add Server\t\t12. Search Server\n";
        cout << "13. Display Servers\n";
        cout << "14. Add Popularity\t15. Display Popularity\n";
        cout << "16. Add Cache File\t17. Delete Cache File\n";
        cout << "18. Display Cache\n";
        cout << "19. Add Connection\t20. Display Network\n";
        cout << "21. BFS Traversal\t22. DFS Traversal\n";
        cout << "23. Shortest Path (Dijkstra)\n";
        cout << "0. Exit\n";

        cout << "\nEnter Choice: ";

        cin >> choice;
        cin.ignore();

        switch (choice)
        {

        case 1:
            s1 = getStr("URL: ");
            s2 = getStr("Server: ");
            um.addURL(s1, s2);
            break;

        case 2:
            um.searchURL(getStr("URL: "));
            break;

        case 3:
            um.deleteURL(getStr("URL: "));
            break;

        case 4:
            um.displayURLs();
            break;

        case 5:
            sm.addAction(getStr("Action: "));
            break;

        case 6:
            sm.undoAction();
            break;

        case 7:
            sm.displayHistory();
            break;

        case 8:
            dq.addDownload(getStr("File: "));
            break;

        case 9:
            dq.processDownload();
            break;

        case 10:
            dq.displayQueue();
            break;

        case 11:
            sd.addServer(getStr("Server: "));
            break;

        case 12:
            sd.searchServer(getStr("Server: "));
            break;

        case 13:
            sd.displayServers();
            break;

        case 14:
            s1 = getStr("File: ");

            cout << "Requests: ";
            cin >> val;
            cin.ignore();

            pm.addFile(s1, val);
            break;

        case 15:
            pm.displayPopularity();
            break;

        case 16:
            cm.insertFile(getStr("Cache File: "));
            break;

        case 17:
            cm.deleteFile(getStr("Delete File: "));
            break;

        case 18:
            cm.displayCache();
            break;

        case 19:
            s1 = getStr("Source Server: ");
            s2 = getStr("Destination Server: ");

            cout << "Latency (ms): ";
            cin >> val;
            cin.ignore();

            ng.addConnection(s1, s2, val);
            break;

        case 20:
            ng.displayGraph();
            break;

        case 21:
            ng.BFS(getStr("Start Server: "));
            break;

        case 22:
            ng.DFS(getStr("Start Server: "));
            break;

        case 23:
            s1 = getStr("Source Server: ");
            s2 = getStr("Destination Server: ");

            ng.shortestPath(s1, s2);
            break;

        case 0:
            cout << "Exiting program...\n";
            break;

        default:
            cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 0);

    return 0;
}