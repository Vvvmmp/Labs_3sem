using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace lab12
{
    internal class LVKDirInfo
    {
        public string Path { get; set; }
        private readonly LVKLog logger;

        public LVKDirInfo(LVKLog log, string path)
        {
            logger = log;
            Path = path;
        }

        public string GetFullInfo()
        {
            var info = new StringBuilder();
            if (Directory.Exists(Path))
            {
                var DirInfo = new DirectoryInfo(Path);

                int fileCount = DirInfo.GetFiles().Length;
                info.AppendLine($"Количество файлов: {fileCount}");

                info.AppendLine($"Время создания: {DirInfo.CreationTime}");

                int subDirCount = DirInfo.GetDirectories().Length;
                info.AppendLine($"Количество поддиректориев: {subDirCount}");

                DirectoryInfo parentDir = DirInfo.Parent;
                info.AppendLine($"Список родительских директорий: {(parentDir != null ? parentDir.FullName : "Нет родительской директории")}");

                logger.WriteLog("Информация о директории", $"Полный путь: {DirInfo.FullName}, Количество файлов: {fileCount}, Количество поддиректориев: {subDirCount}, Время создания: {DirInfo.CreationTime}");
            
            }
            else
            {
                info.AppendLine($"Директорий не найден: {Path}");
                logger.WriteLog("Ошибка", $"Директорий не найден: {Path}");
            }

            return info.ToString();

        }
    }
}
