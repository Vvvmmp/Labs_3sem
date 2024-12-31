using System;
using System.Diagnostics;
using System.Text.RegularExpressions;

namespace lab8
{
    internal class StringProcessing
    {
        public string RemovePunct(string str)
        {
            return Regex.Replace(str, @"[^\w\s]", "");
        }
        public string AddPrefix(string str, string prefix)
        {
            return prefix + str;
        }
        public string ToUpperCase(string str)
        {
            return str.ToUpper();
        }
        public string ToLowerCase(string str)
        {
            return str.ToLower();
        }
        public string ReplaceWord(string str, string oldword,string word) 
        {
            return str.Replace(oldword, word);
        }
        public string ProcessString(string str, string prefix, string oldword, string word) 
        {
            Action<string> process = s =>
            {
                str = RemovePunct(s);               
                str = ToUpperCase(s);
                str = ToLowerCase(s);
            };
            Action<string, string> process2 = (s, v) =>
            {
                str = AddPrefix(s, v);
            };
            Action<string, string, string> process3 = (s, v, q) =>
            {
                str = ReplaceWord(s, v, q);
            };


           
            process(str);
            process2(str, prefix);
            process3(str, oldword, word);
            return str;
        }
    }
}
