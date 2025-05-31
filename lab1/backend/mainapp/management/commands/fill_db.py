from django.core.management.base import BaseCommand
from mainapp.generate_data import gentestdata  # Импорт вашей функции

class Command(BaseCommand):
    help = 'Заполняет БД тестовыми данными'

    def handle(self, *args, **kwargs):
        gentestdata()  # Вызов функции генерации данных
        self.stdout.write("Данные успешно добавлены в БД!")