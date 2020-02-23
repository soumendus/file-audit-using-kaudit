#include "system_headers.h"

class audit_class
{
        private:
                string abs_dir_path;
                map<string,long> h_file;
                vector<string> file_paths;
                vector<string> all_files_in_all_dirs;

        public:
                audit_class(string& path);

                audit_class(vector<string>& fpaths);

                string get_main_dir_path(void);

		void create_in_mem_ds(void);

		void for_all_dir_paths(void);

		void log_dir_access(string path, bool mode);

		void write_to_text_file(string path);

		void collect_files(void);

		vector<string> get_all_files_in_all_dir(void);
		
		void recur_all_files_in_dir(string path);
};
