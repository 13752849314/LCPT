package com.happygh0st.lcptStarter.service.impl;

import com.happygh0st.lcptStarter.service.IPCounterService;
import jakarta.servlet.http.HttpServletRequest;
import org.springframework.stereotype.Service;
import org.springframework.web.context.request.RequestContextHolder;
import org.springframework.web.context.request.ServletRequestAttributes;

import java.util.HashMap;
import java.util.Map;
import java.util.Objects;

@Service
public class IPCounterServiceImpl implements IPCounterService {

    private Map<String, Integer> map = new HashMap<>();

    @Override
    public void count() {
        ServletRequestAttributes servletRequestAttributes = (ServletRequestAttributes) RequestContextHolder.getRequestAttributes();
        HttpServletRequest request = servletRequestAttributes.getRequest();
        String ip = request.getRemoteAddr();
        Integer i = map.get(ip);
        i = Objects.isNull(i) ? 1 : ++i;
        map.put(ip, i);
        map.forEach((key, value) -> {
            System.out.println("ip:" + key + "\tcount:" + value);
        });
    }
}
