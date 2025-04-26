
from django.contrib import admin
from django.urls import path, include
from django.conf import settings
from django.conf.urls.static import static
from rest_framework import routers
from mainapp.views import ClothsViewSet
urlpatterns = [
    path('admin/', admin.site.urls),
    path('api/',
        include([
            path('cloths.get', ClothsViewSet.as_view({'get': 'list'})),
            path('cloths.get/<pk>', ClothsViewSet.as_view({'get': 'retrieve'})),
            path('cloths.create', ClothsViewSet.as_view({'post': 'create'})),
            path('cloths.delete/<pk>', ClothsViewSet.as_view({'delete': 'destroy'})),   
            path('cloths.update/<pk>', ClothsViewSet.as_view({'post': 'update'})),   
        ]))
]

urlpatterns += static(settings.STATIC_URL, document_root = settings.STATIC_ROOT)
