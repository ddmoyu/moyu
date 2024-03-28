struct VodPlayUrl
{
    std::string episode;
    std::string url;
};

struct Video
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
    std::vector<VodPlayUrl> vod_play_url;
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

struct VideoDataList
{
    int code;
    std::string msg;
    int page;
    int pagecount;
    std::string limit;
    int total;
    std::vector<Video> list;
};

// video list [NULL]
struct VideoItem
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
struct ClassType
{
    int type_id;
    std::string type_name;
};
struct VideoList{
    int code;
    std::string msg;
    int page;
    int pagecount;
    int limit;
    int total;
    std::vector<VideoItem> _list;
    std::vector<ClassType> _class;
}

// video page [&pg=] [&t=]


// video detail [&ids=]
struct VideoDetailItem
{
    int vod_id;
    int type_id;
    int type_id_1;
    int group_id;
    std::string vod_name;
    std::string vod_sub;
    std::string vod_en;
    int vod_status;
    char vod_letter;
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
    double vod_score;
    int vod_score_all;
    int vod_score_num;
    std::string vod_time;
    long long vod_time_add;
    long vod_time_hits;
    long vod_time_make;
    long vod_trysee;
    long vod_douban_id;
    double vod_douban_score;
    std::string vod_reurl;
    std::string vod_rel_vod;
    std::string vod_rel_art;
    std::string vod_content;
    std::string vod_play_from;
    std::string vod_play_server;
    std::string vod_play_note;
    std::string vod_play_url;
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
    int type_name;
};
struct VideoDetailData
{
    int code;
    std::string msg;
    int page;
    int pagecount;
    int limit;
    int total;
    std::vector<VideoDetail> videoDetailList;
};

// search api struct [&wd=]
struct SearchItem
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
struct SearchData
{
    int code;
    std::string msg;
    int page;
    int pagecount;
    int limit;
    int total;
    std::vector<SearchItem> searchList;
    std::vector<ClassType> classList;
};