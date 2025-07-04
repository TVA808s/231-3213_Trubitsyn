from django.shortcuts import render

import rest_framework
from rest_framework import  viewsets


from .models import Cloths
from .serializers import ClothsSerializer


class ClothsViewSet(viewsets.ModelViewSet):
    queryset = Cloths.objects.all()
    serializer_class = ClothsSerializer

    # def create(self, request, *args, **kwargs):
    #     return super().create(request, *args, **kwargs)
    
    # def retrieve(self, request, *args, **kwargs):
    #     return super().retrieve(request, *args, **kwargs)
    
    # def update(self, request, *args, **kwargs):
    #     return super().update(request, *args, **kwargs)
    
    # def destroy(self, request, *args, **kwargs):
    #     return super().destroy(request, *args, **kwargs)
    
    # def list(self, request, *args, **kwargs):
    #     return super().list(request, *args, **kwargs)