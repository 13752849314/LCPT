package com.happygh0st.lcptStarter.interceptor;

import com.happygh0st.lcptStarter.service.IPCounterService;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.servlet.HandlerInterceptor;

public class IPCounterInterceptor implements HandlerInterceptor {

    @Autowired
    private  IPCounterService ipCounterService;



    @Override
    public boolean preHandle(HttpServletRequest request, HttpServletResponse response, Object handler) {
        ipCounterService.count();
        return true;
    }
}
