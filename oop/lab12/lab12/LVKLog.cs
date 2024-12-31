using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace lab12
{
    internal class LVKLog
    {
        private string logfile;

        public LVKLog(string logfile = "lvklogfile.txt")
        {
            this.logfile = logfile;
        }

        public void WriteLog(string action, string message)
        {
            string time = DateTime.Now.ToString("yyyy-MM-dd, HH-mm-ss");
            using (StreamWriter sw = new StreamWriter(logfile, true))
            {
                sw.WriteLine($"{time} - {action}: {message}");
            }
        }
        public string ReadLogs()
        {
            return File.ReadAllText(logfile);
        }

        public string[] SearchLogs(string search)
        {
            var result = new List<string>();
            string[] lines = File.ReadAllLines(logfile);
            foreach (string line in lines)
            {
                if (line.Contains(search))
                {
                    result.Add(line);
                }
            }
            return result.Count > 0 ? result.ToArray() : new string[] {"Не найдено"};
        }

        public string[] SearchByTime(DateTime time1, DateTime time2)
        {
            var result = new List<string>();
            string[] lines = File.ReadAllLines(logfile);

            foreach (string line in lines)
            {
                string dateTimePart = line.Substring(0, 19);

                dateTimePart = dateTimePart.Replace('-', ':').Replace(',', ' ');

                if (DateTime.TryParse(dateTimePart, out DateTime logTime))
                {
                    if (logTime >= time1 && logTime <= time2)
                    {
                        result.Add(line); 
                    }
                }
            }

            return result.ToArray();
        }

    }
}
