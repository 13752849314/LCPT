package com.happygh0st.lcptStarter;

import com.happygh0st.lcptStarter.service.IPCounterService;
import com.happygh0st.lcptStarter.service.impl.IPCounterServiceImpl;
import org.springframework.boot.context.properties.EnableConfigurationProperties;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;

@Configuration
@EnableConfigurationProperties(LcptProperties.class)
public class LcptAutoConfiguration {
    @Bean
    public IPCounterService ipCounterService(LcptProperties lcptProperties) {
        System.out.println(lcptProperties.getName());
        return new IPCounterServiceImpl();
    }
}
