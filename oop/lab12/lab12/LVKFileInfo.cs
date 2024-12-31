using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace lab12
{
    internal class LVKFileInfo
    {
        public string Path { get; set; }
        private readonly LVKLog logger;

        public LVKFileInfo(LVKLog log, string path) 
        {
            logger = log;
            Path = path;
        }

        public string GetFullInfo()
        {
            var info = new StringBuilder();
            if (File.Exists(Path))
            {
                var fileInfo = new FileInfo(Path);

                info.AppendLine($"Полный путь: {fileInfo.FullName}");
                info.AppendLine($"Имя файла: {fileInfo.Name}");
                info.AppendLine($"Расширение: {fileInfo.Extension}");
                info.AppendLine($"Размер: {fileInfo.Length} байт");
                info.AppendLine($"Дата создания: {fileInfo.CreationTime}");
                info.AppendLine($"Дата последнего изменения: {fileInfo.LastWriteTime}");

                logger.WriteLog("Информация о файле", $"Полный путь: {fileInfo.FullName}, Размер: {fileInfo.Length}, Расширение: {fileInfo.Extension}, Дата создания: {fileInfo.CreationTime}, Дата изменения: {fileInfo.LastWriteTime}");
            }
            else
            {
                info.AppendLine($"Файл не найден: {Path}");
                logger.WriteLog("Ошибка", $"Файл не найден: {Path}");
            }

            return info.ToString();

        }


    }
}
