using System;
using System.IO;
using System.IO.Compression;
using System.Text;

namespace lab12
{
    internal class LVKFileManager
    {
        public string DirectoryPath { get; set; }
        private readonly LVKLog logger;

        public LVKFileManager(LVKLog log, string path)
        {
            logger = log;
            DirectoryPath = path;
        }

        public string GetFullInfo(string userProvidedPath, string fileExtension)
        {
            var info = new StringBuilder();
            if (Directory.Exists(DirectoryPath))
            {
                string[] files = Directory.GetFiles(DirectoryPath);
                foreach (string file in files)
                {
                    info.AppendLine($"Файл: {file}");
                }

                string[] dirs = Directory.GetDirectories(DirectoryPath);
                foreach (string dir in dirs)
                {
                    info.AppendLine($"Папка: {dir}");
                }

                string newDir = Path.Combine(DirectoryPath, "LVKInspect");
                Directory.CreateDirectory(newDir);

                string filesDir = Path.Combine(DirectoryPath, "LVKFiles");
                Directory.CreateDirectory(filesDir);

                CopyFilesWithExtension(userProvidedPath, filesDir, fileExtension);

                string movedFilesDir = Path.Combine(newDir, "LVKFiles");
                if (Directory.Exists(movedFilesDir))
                {
                    Directory.Delete(movedFilesDir, true);
                }
                Directory.Move(filesDir, movedFilesDir);
                logger.WriteLog("Перемещение директории", $"Перемещена директория: {movedFilesDir}");

                string zipFilePath = Path.Combine(newDir, "LVKFiles.zip");
                ZipFile.CreateFromDirectory(movedFilesDir, zipFilePath);
                logger.WriteLog("Создание архива", $"Создан архив: {zipFilePath}");

                string extractDir = Path.Combine(DirectoryPath, "ExtractedFiles");
                Directory.CreateDirectory(extractDir);
                ZipFile.ExtractToDirectory(zipFilePath, extractDir);
                logger.WriteLog("Разархивирование", $"Разархивировано в: {extractDir}");

                string infoFilePath = Path.Combine(newDir, "lvkdirinfo.txt");
                File.WriteAllText(infoFilePath, info.ToString());
                logger.WriteLog("Создание файла", $"Создан файл: {infoFilePath}");
            }
            else
            {
                info.AppendLine($"Директория не найдена: {DirectoryPath}");
                logger.WriteLog("Ошибка", $"Директория не найдена: {DirectoryPath}");
            }

            return info.ToString();
        }

        private void CopyFilesWithExtension(string sourceDir, string targetDir, string extension)
        {
            if (!Directory.Exists(sourceDir))
            {
                logger.WriteLog("Ошибка", $"Директория не найдена: {sourceDir}");
                return;
            }

            string[] filesToCopy = Directory.GetFiles(sourceDir, $"*{extension}");
            foreach (string file in filesToCopy)
            {
                string fileName = Path.GetFileName(file);
                string destFile = Path.Combine(targetDir, fileName);
                File.Copy(file, destFile, true);
                logger.WriteLog("Копирование файла", $"Скопирован файл: {file} в {destFile}");
            }
        }
    }
}
