class BrowserHistory {
    struct Page {
        std::string url;
        Page* next;
        Page* prev;
        Page(std::string url = "", Page* prev = nullptr, Page* next = nullptr) {
            this->url = url;
            this->next = next;
            this->prev = prev;
        }
    };
    Page* currentPage;

public:

    BrowserHistory(std::string homepage) {
        currentPage = new Page(homepage);
    }

    void visit(std::string url) {
        currentPage->next = new Page(url, currentPage, nullptr);
        currentPage = currentPage->next;
    }

    std::string back(int steps) {
        while (currentPage->prev != nullptr && steps > 0) {
            currentPage = currentPage->prev;
            steps--;
        }
        return currentPage->url;
    }

    std::string forward(int steps) {
        while (currentPage->next != nullptr && steps > 0) {
            currentPage = currentPage->next;
            steps--;
        }
        return currentPage->url;
    }
};