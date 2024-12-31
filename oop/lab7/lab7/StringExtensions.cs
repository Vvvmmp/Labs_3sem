namespace lab7
{
    public static class StringExtensions
    {
        public static string Truncate(this string str, int length)
        {
            if (string.IsNullOrEmpty(str) || length <= 0)
                return string.Empty;

            return str.Length <= length ? str : str.Substring(0, length);
        }

        public static int CountEl(this string str)
        {
            return string.IsNullOrEmpty(str) ? 0 : str.Length;
        }
    }
}