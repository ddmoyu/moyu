#include <string>
#include <vector>

/********************   Video API start   ********************/
// video play urls
struct VideoUrls
{
    std::string episode;
    std::string url;
};

// complete information of the video
struct VideoItem
{
    int vod_id;
    int type_id;
    int type_id_1;
    int group_id;
    std::string vod_name;
    std::string vod_sub;
    std::string vod_en;
    int vod_status;
    std::string vod_letter;
    std::string vod_color;
    std::string vod_tag;
    std::string vod_class;
    std::string vod_pic;
    std::string vod_pic_thumb;
    std::string vod_pic_slide;
    std::string vod_actor;
    std::string vod_director;
    std::string vod_writer;
    std::string vod_behind;
    std::string vod_blurb;
    std::string vod_remarks;
    std::string vod_pubdate;
    int vod_total;
    std::string vod_serial;
    std::string vod_tv;
    std::string vod_weekday;
    std::string vod_area;
    std::string vod_lang;
    std::string vod_year;
    std::string vod_version;
    std::string vod_state;
    std::string vod_author;
    std::string vod_jumpurl;
    std::string vod_tpl;
    std::string vod_tpl_play;
    std::string vod_tpl_down;
    int vod_isend;
    int vod_lock;
    int vod_level;
    int vod_points_play;
    int vod_points_down;
    int vod_hits;
    int vod_hits_day;
    int vod_hits_week;
    int vod_hits_month;
    std::string vod_duration;
    int vod_up;
    int vod_down;
    std::string vod_score;
    int vod_score_all;
    int vod_score_num;
    std::string vod_time;
    std::int64_t vod_time_add;
    int vod_time_hits;
    int vod_time_make;
    int vod_trysee;
    int vod_douban_id;
    std::string vod_douban_score;
    std::string vod_reurl;
    std::string vod_rel_vod;
    std::string vod_rel_art;
    std::string vod_play_from;
    std::string vod_play_server;
    std::string vod_play_note;
    std::vector<VideoUrls> vod_play_url;
    std::string vod_down_from;
    std::string vod_down_server;
    std::string vod_down_note;
    std::string vod_down_url;
    std::string vod_pic_screenshot;
    int vod_plot;
    std::string vod_plot_name;
    std::string vod_plot_detail;
    std::string vod_pwd;
    std::string vod_pwd_url;
    std::string vod_pwd_play;
    std::string vod_pwd_play_url;
    std::string vod_pwd_down;
    std::string vod_pwd_down_url;
    int vod_copyright;
    int vod_points;
    std::string type_name;
};

// simple information about video
struct VideoSimpleItem
{
    int vod_id;
    std::string vod_name;
    int type_id;
    std::string type_name;
    std::string vod_en;
    std::string vod_time;
    std::string vod_remarks;
    std::string vod_play_from;
};

// video class
struct VideoClassType
{
    int type_id;
    std::string type_name;
};

// api base
struct VideoBase
{
    int code;
    std::string msg;
    int page;
    int pagecount;
    int limit;
    int total;
};

// api [&pg=] [&t=] [&ids=]
struct VideoData : VideoBase
{
    std::vector<VideoItem> videoList;
};

// api [&wd=] [NULL]
struct VideoSimpleData : VideoBase
{
    std::vector<VideoSimpleItem> videoList;
    std::vector<VideoClassType> classList;
};
/********************    Video API end    ********************/

/********************  IPTVAPI API start  ********************/
struct IPTVItem
{
    std::string id;
    std::string url;
    std::string name;
    std::string image;
};
/********************   IPTVAPI API end   ********************/

/********************    Feed API start   ********************/
// API
struct APIInfo
{
    std::string version;
    std::string author;
    std::string email;
    std::string website;
    std::string description;
};

struct BaseAPI
{
    std::string id;
    std::string name;
    std::string api;
    bool active;
};

struct NovelAPI : BaseAPI
{ };

struct ImageAPI : BaseAPI
{ };

struct VideoAPI : BaseAPI
{
    std::string group;
    std::string playUrl;
    bool search;
};

struct IPTVAPI : BaseAPI
{ };

struct LiveAPI : BaseAPI
{ };

struct JieXiAPI : BaseAPI
{ };

struct DriveAPI : BaseAPI
{
    std::string start;
};

struct FeedApi
{
    APIInfo info;
    std::vector<NovelAPI> novelApi;
    std::vector<ImageAPI> imageApi;
    std::vector<VideoAPI> videoApi;
    std::vector<IPTVAPI> iptvApi;
    std::vector<LiveAPI> liveApi;
    std::vector<JieXiAPI> JieXiApi;
};
/********************     Feed API end    ********************/

/********************    Settings start   ********************/
struct Settings
{
    std::string version;
    std::string theme;
    std::string player; // self / pot / vlc / mpv
    std::string search; // video / iptv / live / novel / image
    bool windowsPosAndSize;
    std::vector<int> posAndSize; // x y width height
    bool pauseWhenMinimize;

    struct WebDav
    {
        std::string url;
        std::string username;
        std::string password;
    } webdav;
};
/********************     Settings end    ********************/
