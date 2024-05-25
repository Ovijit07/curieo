#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <algorithm> 
using namespace std;

struct LogEntry {
    long long timestamp;
    std::string log_type;
    double severity;

    LogEntry(long long ts, const std::string& lt, double s) : timestamp(ts), log_type(lt), severity(s) {}
};

struct SeverityStats {
    double min_severity;
    double max_severity;
    double mean_severity;
};

std::vector<LogEntry> log_entries;

SeverityStats compute_severity_stats(const std::vector<LogEntry>& entries) {
    if (entries.empty()) {
        SeverityStats stats = {0.0, 0.0, 0.0};
        return stats;
    }
    double min_severity = std::numeric_limits<double>::max();
    double max_severity = std::numeric_limits<double>::lowest();
    double sum_severity = 0.0;
    for (std::vector<LogEntry>::const_iterator it = entries.begin(); it != entries.end(); ++it) {
        const LogEntry& entry = *it;
        min_severity = std::min(min_severity, entry.severity);
        max_severity = std::max(max_severity, entry.severity);
        sum_severity += entry.severity;
    }
    double mean_severity = sum_severity / entries.size();
    SeverityStats stats = {min_severity, max_severity, mean_severity};
    return stats;
}

SeverityStats compute_stats_log_type(const std::string& log_type) {
    std::vector<LogEntry> filtered_entries;
    for (std::vector<LogEntry>::const_iterator it = log_entries.begin(); it != log_entries.end(); ++it) {
        if (it->log_type == log_type) {
            filtered_entries.push_back(*it);
        }
    }
    return compute_severity_stats(filtered_entries);
}

SeverityStats compute_stats_before(long long timestamp) {
    std::vector<LogEntry> filtered_entries;
    for (std::vector<LogEntry>::const_iterator it = log_entries.begin(); it != log_entries.end(); ++it) {
        if (it->timestamp < timestamp) {
            filtered_entries.push_back(*it);
        }
    }
    return compute_severity_stats(filtered_entries);
}

SeverityStats compute_stats_after(long long timestamp) {
    std::vector<LogEntry> filtered_entries;
    for (std::vector<LogEntry>::const_iterator it = log_entries.begin(); it != log_entries.end(); ++it) {
        if (it->timestamp > timestamp) {
            filtered_entries.push_back(*it);
        }
    }
    return compute_severity_stats(filtered_entries);
}

SeverityStats compute_stats_before_log_type(const std::string& log_type, long long timestamp) {
    std::vector<LogEntry> filtered_entries;
    for (std::vector<LogEntry>::const_iterator it = log_entries.begin(); it != log_entries.end(); ++it) {
        if (it->log_type == log_type && it->timestamp < timestamp) {
            filtered_entries.push_back(*it);
        }
    }
    return compute_severity_stats(filtered_entries);
}

SeverityStats compute_stats_after_log_type(const std::string& log_type, long long timestamp) {
    std::vector<LogEntry> filtered_entries;
    for (std::vector<LogEntry>::const_iterator it = log_entries.begin(); it != log_entries.end(); ++it) {
        if (it->log_type == log_type && it->timestamp > timestamp) {
            filtered_entries.push_back(*it);
        }
    }
    return compute_severity_stats(filtered_entries);
}

void solve(){
  int n;
  cin>>n;

  int timestamp;
  string log_type;
  double severity;

  for(int i=0;i<n;i++){
    int flag;
    cin>>flag;
    if(flag==1){
    
        cin>>timestamp;
        cin>>log_type;
        cin>>severity;

        log_entries.push_back(LogEntry(timestamp, log_type, severity));
        cout<<"No Output"<<endl;

    }else if(flag==2){


        cin>>log_type;
        SeverityStats ans=compute_stats_log_type(log_type);
        cout<<"Min: "<<ans.min_severity<<", Max: "<<ans.max_severity<<", Mean: "<<ans.mean_severity<<endl;


    }else if(flag==3){
        string time;
        cin>>time;
        cin>>timestamp;

        if(time=="BEFORE"){
           SeverityStats ans= compute_stats_before(timestamp);
           cout<<"Min: "<<ans.min_severity<<", Max: "<<ans.max_severity<<", Mean: "<<ans.mean_severity<<endl;

        }else{

          SeverityStats ans=   compute_stats_after(timestamp);
          cout<<"Min: "<<ans.min_severity<<", Max: "<<ans.max_severity<<", Mean: "<<ans.mean_severity<<endl;

        }

    }else{
    
        string time;

         cin>>time;
         cin>>log_type;
        cin>>timestamp;

        if(time=="BEFORE"){
           SeverityStats ans= compute_stats_before_log_type(log_type,timestamp);
           cout<<"Min: "<<ans.min_severity<<", Max: "<<ans.max_severity<<", Mean: "<<ans.mean_severity<<endl;

        }else{
            SeverityStats ans= compute_stats_after_log_type(log_type,timestamp);
            cout<<"Min: "<<ans.min_severity<<", Max: "<<ans.max_severity<<", Mean: "<<ans.mean_severity<<endl;

        }

    }
  }

}


int main(){
    solve();
}