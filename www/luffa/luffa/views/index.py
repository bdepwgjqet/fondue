from django.shortcuts import render_to_response

__author__ = 'yonghong.yyh'

def index(request):
    return render_to_response('time/current_datetime.html', locals())
