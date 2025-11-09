"use client";

import { produce } from "immer";
import { Task } from "@/components/Task";
import { useState } from "react";

export type Status = "next" | "current" | "done";

export interface ITask {
  id: string;
  title: string;
  status: Status;
}

export default function Home() {
  const [title, setTask] = useState("");
  const [tasks, setTasks] = useState<ITask[]>([]);

  const addTask = () => {
    if (!title) return;

    const newTask: ITask = { id: new Date().toTimeString(), title: title, status: "next" };

    const newState = produce(tasks, (draft) => {
      draft.push(newTask);
    });

    setTasks(newState);
    setTask("");
  };

  const removeTask = (id: string) => {
    const newState = produce(tasks, (draft) => {
      const index = draft.findIndex((task) => task.id === id);
      draft.splice(index, 1);
    });

    setTasks(newState);
  };

  const updateTask = (newTask: ITask) => {
    const newState = produce(tasks, (draft) => {
      const index = draft.findIndex((task) => task.id === newTask.id);
      draft.splice(index, 1, newTask);
    });

    setTasks(newState);
  };

  return (
    <>
      <form onSubmit={(e) => (e.preventDefault(), addTask())} className="flex w-4xl m-[10em_5em] justify-between">
        <input
          autoFocus
          className="bg-neutral-900 mr-8 p-[10px_20px] outline-none grow"
          type="text"
          placeholder="Nova tarefa..."
          value={title}
          onChange={(e) => setTask(e.target.value)}
        />
        <button className="bg-blue-600 cursor-pointer p-[10px_20px]">Adicionar</button>
      </form>

      <div className="w-4xl">
        {tasks.map((task) => (
          <Task props={{ task, removeTask, updateTask }} key={task.id} />
        ))}
      </div>
    </>
  );
}
