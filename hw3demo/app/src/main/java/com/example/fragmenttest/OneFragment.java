package com.example.fragmenttest;


import android.animation.ObjectAnimator;
import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.TextView;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;
import androidx.fragment.app.Fragment;

public class OneFragment extends Fragment {

    private TextView textView;

    @Override
    public void onCreate(@Nullable Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
    }

    @Nullable
    @Override
    public View onCreateView(@NonNull LayoutInflater inflater, @Nullable ViewGroup container, @Nullable Bundle savedInstanceState) {
        View view = inflater.inflate(R.layout.fragment_one, null);
        return view;
    }

    @Override
    public void onResume() {
        super.onResume();
        textView = getView().findViewById(R.id.textview1);
        ObjectAnimator.ofFloat(textView, "translationX", 800).setDuration(10000).start();
    }
}
