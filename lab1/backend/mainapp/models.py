from django.db import models
# python manage.py makemigrations

class Cloths(models.Model):
    brand = models.CharField(max_length=32, null=True)
    category = models.CharField(max_length=32, null=True)
    price = models.DecimalField(null=True, max_digits=10, decimal_places=2)
    color = models.CharField(max_length=16, null=True)
    used = models.BooleanField(null=True)
    season = models.DateField(null=True)
    description = models.TextField(null=True)
# Create your models here.

