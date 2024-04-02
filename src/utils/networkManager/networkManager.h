#include <QNetworkAccessManager>

class NetworkManager
{
public:
    static NetworkManager& instance()
    {
        static NetworkManager _instance;
        return _instance;
    }

    QNetworkAccessManager* manager() { return &m_networkManager; }

private:
    NetworkManager() { }
    ~NetworkManager() { }

    NetworkManager(const NetworkManager&)            = delete;
    NetworkManager& operator=(const NetworkManager&) = delete;

    QNetworkAccessManager m_networkManager;
};